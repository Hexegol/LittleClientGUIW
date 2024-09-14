#pragma once
#include <Windows.h>
#include <TlHelp32.h>
class Utils
{
public:
	DWORD GetPID(const char* ProcessName);
	MODULEENTRY32 GetModule(const char* moduleName, unsigned long ProcessID);
	uintptr_t dwGetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID);
};

