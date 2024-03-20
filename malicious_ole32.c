#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            OutputDebugStringA("I'm not the original ole32.dll >:)");
            break;
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}