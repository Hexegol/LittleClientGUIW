#include "pch.h"
#include "Utils.h"
#include<tchar.h>

DWORD Utils::GetPID(const char* ProcessName)
{
    PROCESSENTRY32 processInfo;
    processInfo.dwSize = sizeof(PROCESSENTRY32);

    HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (processesSnapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }

    if (Process32First(processesSnapshot, &processInfo)) {
        do {
            if (!strcmp(processInfo.szExeFile, ProcessName)) {
                DWORD pid = processInfo.th32ProcessID;
                CloseHandle(processesSnapshot);
                return pid;
            }
        } while (Process32Next(processesSnapshot, &processInfo));
    }


    CloseHandle(processesSnapshot);

}

MODULEENTRY32 Utils::GetModule(const char* moduleName, unsigned long ProcessID)
{
    MODULEENTRY32 modEntry = { 0 };

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, ProcessID);

    if (hSnapshot != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 curr = { 0 };

        curr.dwSize = sizeof(MODULEENTRY32);
        if (Module32First(hSnapshot, &curr))
        {
            do
            {
                if (!strcmp(curr.szModule, moduleName))
                {
                    modEntry = curr;
                    break;
                }
            } while (Module32Next(hSnapshot, &curr));
        }
        CloseHandle(hSnapshot);
    }
    return modEntry;

}

uintptr_t Utils::dwGetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID)
{
    uintptr_t dwModuleBaseAddress = 0;
    HANDLE hSnapshoot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
    MODULEENTRY32 ModuleEntry32 = { 0 };
    ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

    if (Module32First(hSnapshoot, &ModuleEntry32))
    {
        do {
            if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0)
            {
                dwModuleBaseAddress = (uintptr_t)ModuleEntry32.modBaseAddr;
                break;
            }
        } while (Module32Next(hSnapshoot, &ModuleEntry32));

    }
    CloseHandle(hSnapshoot);
    return dwModuleBaseAddress;

}
