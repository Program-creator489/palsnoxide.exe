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

#include "color.h"
#include "effects.h"
#include "sound.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

    if (MessageBoxW(NULL, L"The software you just executed is considered a safety GDI program.\r\n\
This software will not overwrite the Mbr or make changes to your computer.\r\n\
Credits to program-creator-489 for making this GDI.\r\n\
If you still don't trust this software you can run it in a Virtual Mechine, \
If you know what your about to see on your screen press Yes.\r\n\r\n\
This software is 100% non malicous.", L"palsnoxide-safety.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else
    {
        if (MessageBoxW(NULL, L"THIS IS THE LAST WARNING!\r\n\r\n\
This is the last time you can cancel the GDI effects from running,\r\n\
STILL EXECUTE IT?", L"palsnoxide-safety.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else {

            Sleep(5000);
            HANDLE P1 = CreateThread(0, 0, RGB1, 0, 0, 0);
            sound1();
            Sleep(30000);
            TerminateThread(P1, 0);
            CloseHandle(P1);
            Sleep(100);
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

        }
    }
}