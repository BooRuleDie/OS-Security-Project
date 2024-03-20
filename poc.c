#include <stdio.h>
#include <windows.h>

int main() {
    // Attempt to load a non-existent DLL
    HMODULE hDll = LoadLibrary("nonexistent.dll");

    // Check if DLL loading failed
    if (hDll == NULL) {
        // Get the error code
        DWORD dwError = GetLastError();

        // Check if the error code indicates that the DLL was not found
        if (dwError == ERROR_MOD_NOT_FOUND) {
            printf("The specified DLL does not exist.\n");
        } else {
            // Print a generic error message
            printf("Failed to load DLL. Error code: %lu\n", dwError);
        }
    } else {
        // If the DLL was loaded successfully, free the module handle
        FreeLibrary(hDll);
    }

    return 0;
}
