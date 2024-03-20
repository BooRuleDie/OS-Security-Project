#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            MessageBoxA(NULL, "I'm not the original ole32.dll >:)", "Custom DLL Message", MB_OK);
            break;
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}