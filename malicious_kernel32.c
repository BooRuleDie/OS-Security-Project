// malicious_kernel32.c
#include <windows.h>
#include <stdio.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            printf("I'm not the right kernel32.dll >:)\n");
            break;
    }
    return TRUE;
}