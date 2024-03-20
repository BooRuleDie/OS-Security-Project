#include <stdio.h>
#include <windows.h>
#include <initguid.h>
#include <objbase.h>

int main() {
    HMODULE hDll = LoadLibraryA("ole32.dll");
    if (hDll == NULL) {
        printf("Failed to load ole32.dll\n");
        return 1;
    }

    printf("ole32.dll loaded successfully!\n");

    FreeLibrary(hDll);
    return 0;
}