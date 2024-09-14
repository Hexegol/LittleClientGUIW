#include "pch.h"
#include "Fly.h"
#include "Utils.h"

Cheat::Fly::Fly()
{
}

Cheat::Fly::~Fly()
{
	delete this;
}

void Cheat::Fly::EnableFly()
{
    Utils* utils = new Utils();

    unsigned long long pid = utils->GetPID("Minecraft.Windows.exe");
    MODULEENTRY32 module = utils->GetModule("Minecraft.Windows.exe", pid);
    HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    char moduleName[] = "Minecraft.Windows.exe";
    DWORD oldProtect = 0;
    uintptr_t clientbase = utils->dwGetModuleBaseAddress((moduleName), pid);

    uintptr_t fly = clientbase + 0x37726e5;
    VirtualProtectEx(phandle, (LPVOID)(fly), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
    WriteProcessMemory(phandle, (LPVOID)(fly), "\xC7\x42\x04\x01\x00\x00\x00", 7, nullptr);
}

void Cheat::Fly::DisableFly()
{
    Utils* utils = new Utils();

    unsigned long long pid = utils->GetPID("Minecraft.Windows.exe");
    MODULEENTRY32 module = utils->GetModule("Minecraft.Windows.exe", pid);
    HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    char moduleName[] = "Minecraft.Windows.exe";
    DWORD oldProtect = 0;
    uintptr_t clientbase = utils->dwGetModuleBaseAddress((moduleName), pid);

    uintptr_t fly = clientbase + 0x37726e5;
    VirtualProtectEx(phandle, (LPVOID)(fly), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
    WriteProcessMemory(phandle, (LPVOID)(fly), "\x80\x7A\x04\x00", 4, nullptr);
}
