/*
 * DOS interrupt 09h handler (IRQ1 - KEYBOARD)
 */

#include <stdlib.h>
#include <string.h>
#include "winuser.h"
#include "miscemu.h"
#include "input.h"
#include "debug.h"
#include "dosexe.h"

typedef struct {
  BYTE queuelen,queue[15];
} KBDSYSTEM;

/**********************************************************************
 *	    INT_Int09Handler
 *
 * Handler for int 09h.
 */
void WINAPI INT_Int09Handler( CONTEXT *context )
{
  BYTE scan = INT_Int09ReadScan();
  UINT vkey = MapVirtualKeyA(scan&0x7f, 1);
  BYTE ch[2];
  int cnt;

  if (!(scan & 0x80)) {
    /* as in TranslateMessage, windows/input.c */
    cnt = ToAscii(vkey, scan&0x7f, QueueKeyStateTable, (LPWORD)ch, 0);
    if (cnt==1) {
      FIXME(int,"enter character %c into console input, not implemented\n",ch[0]);
    }
  }
  DOSVM_PIC_ioport_out(0x20, 0x20); /* send EOI */
}

static void KbdRelay( LPDOSTASK lpDosTask, PCONTEXT context, void *data )
{
  KBDSYSTEM *sys = (KBDSYSTEM *)DOSVM_GetSystemData(0x09);

  if (sys && sys->queuelen) {
    /* cleanup operation, called from DOSVM_PIC_ioport_out:
     * we'll remove current scancode from keyboard buffer here,
     * rather than in ReadScan, because some DOS apps depend on
     * the scancode being available for reading multiple times... */
    if (--sys->queuelen)
      memmove(sys->queue,sys->queue+1,sys->queuelen);
  }
}

void WINAPI INT_Int09SendScan( BYTE scan )
{
  KBDSYSTEM *sys = (KBDSYSTEM *)DOSVM_GetSystemData(0x09);
  if (!sys) {
    sys = calloc(1,sizeof(KBDSYSTEM));
    DOSVM_SetSystemData(0x09,sys);
  }
  /* add scancode to queue */
  sys->queue[sys->queuelen++] = scan;
  /* tell app to read it by triggering IRQ 1 (int 09) */
  DOSVM_QueueEvent(1,DOS_PRIORITY_KEYBOARD,KbdRelay,NULL);
}

BYTE WINAPI INT_Int09ReadScan( void )
{
  KBDSYSTEM *sys = (KBDSYSTEM *)DOSVM_GetSystemData(0x09);
  if (sys)
    return sys->queue[0];
  else
    return 0;
}
