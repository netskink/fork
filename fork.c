/*++

This program is simply a place to test things.
--*/


#include "dbgzero.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include "common.h"
#include "usrlib.h"


//my_main(argc,argv[]) {
main(int argc,char *argv[]) {

	BOOL Result;
	
#ifdef WIN32
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
#endif


	/* determine if this is a reader or a writer invocation. */
	/* make sre we have at least one argument for the mode. */
	if (argc < 2) {
		myprint("USAGE: %s <app>\n",argv[0]);
		my_exit(1);
	}
	
#ifdef WIN32

	// BOOL WINAPI CreateProcess(
	// __in_opt     LPCTSTR lpApplicationName,
	// __inout_opt  LPTSTR lpCommandLine,
	// __in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
	// __in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
	// __in         BOOL bInheritHandles,
	// __in         DWORD dwCreationFlags,
	// __in_opt     LPVOID lpEnvironment,
	// __in_opt     LPCTSTR lpCurrentDirectory,
	// __in         LPSTARTUPINFO lpStartupInfo,
	// __out        LPPROCESS_INFORMATION lpProcessInformation
	// );
	myprint("\n%s\n",argv[1]);

	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	si.cb = sizeof(si);

	Result = CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

#endif

	if( Result == FALSE ) {
		myprint ("Some sort of error(%u)\n", my_get_last_error() );
		return FALSE;
	}

	myprint("Normal exit \n");

#ifdef WIN32
//    myprint("\n *** Hit enter to continue\n");
	getchar();
#endif
	return 0;
}




