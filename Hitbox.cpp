#include "pch.h"
#include "Hitbox.h"
#include "Utils.h"
#include <windows.h>

Cheat::Hitbox::Hitbox()
{
}

Cheat::Hitbox::~Hitbox()
{
	delete this;
}

void Cheat::Hitbox::EnableHitbox()
{
	Utils* utils = new Utils();

	unsigned long long pid = utils->GetPID("Minecraft.Windows.exe");
	MODULEENTRY32 module = utils->GetModule("Minecraft.Windows.exe", pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	char moduleName[] = "Minecraft.Windows.exe";
	DWORD oldProtect = 0;
	uintptr_t clientbase = utils->dwGetModuleBaseAddress((moduleName), pid);

	uintptr_t hitbox = clientbase + 0x26f9387;
	VirtualProtectEx(phandle, (LPVOID)(hitbox), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(phandle, (LPVOID)(hitbox), "\xC7\x40\x18\x00\x00\xC0\x40", 4, nullptr);
}

void Cheat::Hitbox::DisableHitbox()
{
	Utils* utils = new Utils();

	unsigned long long pid = utils->GetPID("Minecraft.Windows.exe");
	MODULEENTRY32 module = utils->GetModule("Minecraft.Windows.exe", pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	char moduleName[] = "Minecraft.Windows.exe";
	DWORD oldProtect = 0;
	uintptr_t clientbase = utils->dwGetModuleBaseAddress((moduleName), pid);

	uintptr_t hitbox = clientbase + 0x37726e5;
	VirtualProtectEx(phandle, (LPVOID)(hitbox), 256, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(phandle, (LPVOID)(hitbox), "\xF3\x0F\x10\x40\x18", 5, nullptr);
}
