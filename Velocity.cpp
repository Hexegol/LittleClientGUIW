#include "pch.h"
#include "Velocity.h"
#include "Utils.h"
#include <windows.h>

Cheat::Velocity::Velocity()
{
}

Cheat::Velocity::~Velocity()
{
	delete this;
}

void Cheat::Velocity::EnableAntiKb()
{
    Utils* utils = new Utils();

    unsigned long long pid = utils->GetPID("Minecraft.Windows.exe");
    MODULEENTRY32 module = utils->GetModule("Minecraft.Windows.exe", pid);
    HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    char moduleName[] = "Minecraft.Windows.exe";
    DWORD oldProtect = 0;
    uintptr_t clientbase = utils->dwGetModuleBaseAddress((moduleName), pid);

    uintptr_t velocity1 = clientbase + 0x26BA7E4;
    VirtualProtectEx(phandle, (LPVOID)(velocity1), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
    WriteProcessMemory(phandle, (LPVOID)(velocity1), "\x90\x90\x90\x90", 4, nullptr);

    uintptr_t velocity2 = clientbase + 0x26BA7E8;
    VirtualProtectEx(phandle, (LPVOID)(velocity2), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
    WriteProcessMemory(phandle, (LPVOID)(velocity2), "\x90\x90\x90\x90\x90", 5, nullptr);

    uintptr_t velocity3 = clientbase + 0x26BA7ED;
    VirtualProtectEx(phandle, (LPVOID)(velocity3), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
    WriteProcessMemory(phandle, (LPVOID)(velocity3), "\x90\x90\x90\x90", 4, nullptr);
}

void Cheat::Velocity::DisableAntiKb()
{
	Utils* utils = new Utils();

	unsigned long long pid = utils->GetPID("Minecraft.Windows.exe");
	MODULEENTRY32 module = utils->GetModule("Minecraft.Windows.exe", pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	char moduleName[] = "Minecraft.Windows.exe";
	DWORD oldProtect = 0;
	uintptr_t clientbase = utils->dwGetModuleBaseAddress((moduleName), pid);

	uintptr_t velocity1 = clientbase + 0x26BA7E4;
	VirtualProtectEx(phandle, (LPVOID)(velocity1), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(phandle, (LPVOID)(velocity1), "\xF2\x0F\x10\x00", 4, nullptr);

	uintptr_t velocity2 = clientbase + 0x26BA7E8;
	VirtualProtectEx(phandle, (LPVOID)(velocity2), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(phandle, (LPVOID)(velocity2), "\xF2\x0F\x11\x80\x12\x00\x00\x00", 8, nullptr);

	uintptr_t velocity3 = clientbase + 0x26BA7ED;
	VirtualProtectEx(phandle, (LPVOID)(velocity3), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(phandle, (LPVOID)(velocity3), "\x89\x40\x14\x00\x00\x00", 6, nullptr);
}
