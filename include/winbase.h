#ifndef __WINE_WINBASE_H
#define __WINE_WINBASE_H

#include "windows.h"

#ifdef __cplusplus
extern "C" {
#endif

#define WAIT_FAILED		0xffffffff
#define WAIT_OBJECT_0		0
#define WAIT_ABANDONED		STATUS_ABANDONED_WAIT_0
#define WAIT_ABANDONED_0	STATUS_ABANDONED_WAIT_0
#define WAIT_IO_COMPLETION	STATUS_USER_APC
#define WAIT_TIMEOUT		STATUS_TIMEOUT

#define	PAGE_NOACCESS		0x01
#define	PAGE_READONLY		0x02
#define	PAGE_READWRITE		0x04
#define	PAGE_WRITECOPY		0x08
#define	PAGE_EXECUTE		0x10
#define	PAGE_EXECUTE_READ	0x20
#define	PAGE_EXECUTE_READWRITE	0x40
#define	PAGE_EXECUTE_WRITECOPY	0x80
#define	PAGE_GUARD		0x100
#define	PAGE_NOCACHE		0x200

#define MEM_COMMIT              0x00001000
#define MEM_RESERVE             0x00002000
#define MEM_DECOMMIT            0x00004000
#define MEM_RELEASE             0x00008000
#define MEM_FREE                0x00010000
#define MEM_PRIVATE             0x00020000
#define MEM_MAPPED              0x00040000
#define MEM_TOP_DOWN            0x00100000

#define SEC_FILE                0x00800000
#define SEC_IMAGE               0x01000000
#define SEC_RESERVE             0x04000000
#define SEC_COMMIT              0x08000000
#define SEC_NOCACHE             0x10000000

#define FILE_BEGIN              0
#define FILE_CURRENT            1
#define FILE_END                2

#define FILE_CASE_SENSITIVE_SEARCH      0x00000001
#define FILE_CASE_PRESERVED_NAMES       0x00000002
#define FILE_UNICODE_ON_DISK            0x00000004
#define FILE_PERSISTENT_ACLS            0x00000008

#define FILE_MAP_COPY                   0x00000001
#define FILE_MAP_WRITE                  0x00000002
#define FILE_MAP_READ                   0x00000004
#define FILE_MAP_ALL_ACCESS             0x000f001f

#define MOVEFILE_REPLACE_EXISTING       0x00000001
#define MOVEFILE_COPY_ALLOWED           0x00000002
#define MOVEFILE_DELAY_UNTIL_REBOOT     0x00000004

#define FS_CASE_SENSITIVE               FILE_CASE_SENSITIVE_SEARCH
#define FS_CASE_IS_PRESERVED            FILE_CASE_PRESERVED_NAMES
#define FS_UNICODE_STORED_ON_DISK       FILE_UNICODE_ON_DISK


#define STATUS_SUCCESS                   0x00000000
#define STATUS_WAIT_0                    0x00000000    
#define STATUS_ABANDONED_WAIT_0          0x00000080    
#define STATUS_USER_APC                  0x000000C0    
#define STATUS_TIMEOUT                   0x00000102    
#define STATUS_PENDING                   0x00000103    
#define STATUS_GUARD_PAGE_VIOLATION      0x80000001    
#define STATUS_DATATYPE_MISALIGNMENT     0x80000002    
#define STATUS_BREAKPOINT                0x80000003    
#define STATUS_SINGLE_STEP               0x80000004    
#define	STATUS_BUFFER_OVERFLOW           0x80000005
#define STATUS_ACCESS_VIOLATION          0xC0000005    
#define STATUS_IN_PAGE_ERROR             0xC0000006    
#define STATUS_INVALID_PARAMETER         0xC000000D
#define STATUS_NO_MEMORY                 0xC0000017    
#define STATUS_ILLEGAL_INSTRUCTION       0xC000001D    
#define	STATUS_BUFFER_TOO_SMALL          0xC0000023
#define STATUS_NONCONTINUABLE_EXCEPTION  0xC0000025    
#define STATUS_INVALID_DISPOSITION       0xC0000026    
#define	STATUS_UNKNOWN_REVISION          0xC0000058
#define	STATUS_INVALID_SECURITY_DESCR    0xC0000079
#define STATUS_ARRAY_BOUNDS_EXCEEDED     0xC000008C    
#define STATUS_FLOAT_DENORMAL_OPERAND    0xC000008D    
#define STATUS_FLOAT_DIVIDE_BY_ZERO      0xC000008E    
#define STATUS_FLOAT_INEXACT_RESULT      0xC000008F    
#define STATUS_FLOAT_INVALID_OPERATION   0xC0000090    
#define STATUS_FLOAT_OVERFLOW            0xC0000091    
#define STATUS_FLOAT_STACK_CHECK         0xC0000092    
#define STATUS_FLOAT_UNDERFLOW           0xC0000093    
#define STATUS_INTEGER_DIVIDE_BY_ZERO    0xC0000094    
#define STATUS_INTEGER_OVERFLOW          0xC0000095    
#define STATUS_PRIVILEGED_INSTRUCTION    0xC0000096    
#define	STATUS_INVALID_PARAMETER_2       0xC00000F0
#define STATUS_STACK_OVERFLOW            0xC00000FD    
#define STATUS_CONTROL_C_EXIT            0xC000013A    

#define DUPLICATE_CLOSE_SOURCE		0x00000001
#define DUPLICATE_SAME_ACCESS		0x00000002

#define HANDLE_FLAG_INHERIT             0x00000001
#define HANDLE_FLAG_PROTECT_FROM_CLOSE  0x00000002

#define THREAD_PRIORITY_LOWEST          THREAD_BASE_PRIORITY_MIN
#define THREAD_PRIORITY_BELOW_NORMAL    (THREAD_PRIORITY_LOWEST+1)
#define THREAD_PRIORITY_NORMAL          0
#define THREAD_PRIORITY_HIGHEST         THREAD_BASE_PRIORITY_MAX
#define THREAD_PRIORITY_ABOVE_NORMAL    (THREAD_PRIORITY_HIGHEST-1)
#define THREAD_PRIORITY_ERROR_RETURN    (0x7fffffff)
#define THREAD_PRIORITY_TIME_CRITICAL   THREAD_BASE_PRIORITY_LOWRT
#define THREAD_PRIORITY_IDLE            THREAD_BASE_PRIORITY_IDLE

typedef struct 
{
  int type;
} wine_exception;

typedef struct 
{
  int pad[39];
  int edi;
  int esi;
  int ebx;
  int edx;
  int ecx;
  int eax;

  int ebp;
  int eip;
  int cs;
  int eflags;
  int esp;
  int ss;
} exception_info;

/* Could this type be considered opaque? */
typedef struct {
	LPVOID	DebugInfo;
	LONG LockCount;
	LONG RecursionCount;
	HANDLE32 OwningThread;
	HANDLE32 LockSemaphore;
	DWORD Reserved;
}CRITICAL_SECTION;

typedef struct {
        DWORD dwOSVersionInfoSize;
        DWORD dwMajorVersion;
        DWORD dwMinorVersion;
        DWORD dwBuildNumber;
        DWORD dwPlatformId;
        CHAR szCSDVersion[128];
} OSVERSIONINFO16;

typedef struct {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	CHAR szCSDVersion[128];
} OSVERSIONINFO32A;

typedef struct {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	WCHAR szCSDVersion[128];
} OSVERSIONINFO32W;

DECL_WINELIB_TYPE_AW(OSVERSIONINFO)

#define VER_PLATFORM_WIN32s             0
#define VER_PLATFORM_WIN32_WINDOWS      1
#define VER_PLATFORM_WIN32_NT           2

/*DWORD WINAPI GetVersion( void );*/
BOOL16 WINAPI GetVersionEx16(OSVERSIONINFO16*);
BOOL32 WINAPI GetVersionEx32A(OSVERSIONINFO32A*);
BOOL32 WINAPI GetVersionEx32W(OSVERSIONINFO32W*);
#define GetVersionEx WINELIB_NAME_AW(GetVersionEx)

/*int WinMain(HINSTANCE, HINSTANCE prev, char *cmd, int show);*/

void      WINAPI DeleteCriticalSection(CRITICAL_SECTION *lpCrit);
void      WINAPI EnterCriticalSection(CRITICAL_SECTION *lpCrit);
void      WINAPI InitializeCriticalSection(CRITICAL_SECTION *lpCrit);
void      WINAPI LeaveCriticalSection(CRITICAL_SECTION *lpCrit);
HANDLE32  WINAPI OpenProcess(DWORD access, BOOL32 inherit, DWORD id);
BOOL32    WINAPI GetProcessWorkingSetSize(HANDLE32,LPDWORD,LPDWORD);
BOOL32    WINAPI SetProcessWorkingSetSize(HANDLE32,DWORD,DWORD);
void      WINAPI RaiseException(DWORD,DWORD,DWORD,const LPDWORD);
BOOL32    WINAPI TerminateProcess(HANDLE32,DWORD);
BOOL32    WINAPI TerminateThread(HANDLE32,DWORD);

#ifdef __cplusplus
}
#endif

#endif  /* __WINE_WINBASE_H */
