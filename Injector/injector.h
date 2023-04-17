#include <Windows.h>
#include <TlHelp32.h>

#define SHOW_FATAL_ERROR(Msg) \
	MessageBoxW(NULL, L##Msg, L"DAR Injector: Fatal Error", MB_ICONERROR);

#define DAR_DLL_NAME L"DisableAutoReverse.dll"
