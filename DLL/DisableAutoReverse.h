#pragma once

#include <windows.h>
#include <cstdio>

#include "include\detours.h"
#include "include\data_types.h"
#include "Logging.h"

#define DAR_DLL_NAME L"DisableAutoReverse.dll"

//Attaches or detaches hook function Hook_Src to SnowRunner function Src
#define DETOUR_ATTACH(Src)                                                     \
  DetourAttach(&(PVOID &)Src, (PVOID)Hook_##Src);
#define DETOUR_DETACH(Src)                                                     \
  DetourDetach(&(PVOID &)Src, (PVOID)Hook_##Src);
  
//How long we have to wait, in milliseconds, between "blocked" messages
#define MIN_MESSAGE_INTERVAL 1000 

//Initializes mod when DLL is loaded
void Init();

//Shamelessly borrowed
template <typename T> inline T* GetPtrToOffset(int64_t offset) {
	HMODULE base = GetModuleHandleA(NULL);

	return (T*)((BYTE*)base + offset);
}

//Defines the function Name as a pointer to the original Snowrunner function, and
//Defines the function Hook_Name as our hook for that function
#define DAR_GAME_FUNCTION(Offset, R, Name, ...)						\
	auto *Name = GetPtrToOffset<R(__VA_ARGS__)>(Offset);		\
	R Hook_##Name(__VA_ARGS__);

DAR_GAME_FUNCTION(0xd4d420, bool, ShiftGear, Vehicle*, int32_t)
