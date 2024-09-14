#include "pch.h"
#include "Reach.h"
#include "Utils.h"
#include <iostream>

Cheat::Reach::Reach()
{
}

Cheat::Reach::~Reach()
{
	delete this;
}

void Cheat::Reach::ChangeReach(float value)
{
    Utils* utils = new Utils();

    unsigned long long pid = utils->GetPID("Minecraft.Windows.exe");
    MODULEENTRY32 module = utils->GetModule("Minecraft.Windows.exe", pid);
    HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    char moduleName[] = "Minecraft.Windows.exe";
    DWORD oldProtect = 0;
    uintptr_t clientbase = utils->dwGetModuleBaseAddress((moduleName), pid);

    uintptr_t reach = clientbase + 0x52880A8;
    VirtualProtectEx(phandle, (LPVOID)(reach), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
    WriteProcessMemory(phandle, (LPCVOID*)reach, &value, sizeof(value), nullptr);
}
