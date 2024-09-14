#include "pch.h"
#include "Timer.h"
#include "Utils.h"
#include <iostream>

using namespace System::Windows::Forms;
Cheat::timer::timer()
{
}

Cheat::timer::~timer()
{
	delete this;
}

void Cheat::timer::ChangeSpeed(float value)
{
	Utils* utils = new Utils();

	unsigned long long pid = utils->GetPID("Minecraft.Windows.exe");
	MODULEENTRY32 module = utils->GetModule("Minecraft.Windows.exe", pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	char moduleName[] = "Minecraft.Windows.exe";
	DWORD oldProtect = 0;
	uintptr_t clientbase = utils->dwGetModuleBaseAddress((moduleName), pid);

    uintptr_t timer = clientbase + 0x05AD91E8;
    VirtualProtectEx(phandle, (LPVOID)(timer), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
    unsigned long long result;
    float timervalue = value;

    ReadProcessMemory(phandle, (void*)((unsigned long long)clientbase + 0x05AD91E8), &result, sizeof(result), 0);
    ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x0), &result, sizeof(result), 0);
    ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x58), &result, sizeof(result), 0);
    ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x188), &result, sizeof(result), 0);
    ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x388), &result, sizeof(result), 0);
    ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x10), &result, sizeof(result), 0);
    ReadProcessMemory(phandle, (void*)((unsigned long long)result + 0x480), &result, sizeof(result), 0);
    WriteProcessMemory(phandle, (void*)((unsigned long long)result + 0x0), &timervalue, sizeof(timervalue), 0);
    Sleep(10);
}




