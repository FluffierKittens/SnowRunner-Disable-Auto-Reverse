#include <Windows.h>
#include <TlHelp32.h>

#define SHOW_FATAL_ERROR(Msg) \
	MessageBox(NULL, Msg, "DAR Injector: Fatal Error", MB_ICONERROR);

#define DAR_DLL_NAME L"DisableAutoReverse.dll"