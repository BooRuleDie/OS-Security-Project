// DLLExample.c
#include <stdio.h>
#include <windows.h>

// Declare the function prototype for the function we want to import from kernel32.dll
typedef DWORD (__stdcall *GetCurrentProcessIdFunc)(void);

int main() {
    HMODULE hKernel32;                  // Handle to the kernel32.dll module
    GetCurrentProcessIdFunc getCurrentProcessId;  // Function pointer to GetCurrentProcessId

    // Load the kernel32.dll dynamically
    hKernel32 = LoadLibrary("kernel32.dll");
    if (hKernel32 == NULL) {
        printf("Failed to load kernel32.dll: %d\n", GetLastError());
        return 1;
    }

    // Get the address of the GetCurrentProcessId function
    getCurrentProcessId = (GetCurrentProcessIdFunc)GetProcAddress(hKernel32, "GetCurrentProcessId");
    if (getCurrentProcessId == NULL) {
        printf("Failed to get function address: %d\n", GetLastError());
        FreeLibrary(hKernel32);
        return 1;
    }

    // Call the GetCurrentProcessId function from kernel32.dll
    DWORD processId = getCurrentProcessId();
    printf("Current Process ID: %lu\n", processId);

    // Clean up
    FreeLibrary(hKernel32);

    return 0;
}