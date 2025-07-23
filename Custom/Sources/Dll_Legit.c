#include <windows.h>
#include <objbase.h> // Required for COM interfaces and HRESULT
#include <stdio.h>

// Define DLLEXPORT for easy export syntax
#define DLLEXPORT __declspec(dllexport)

// DllMain
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            // This block runs when the DLL is first loaded into a process.
            printf("[+] Test DLL (test.dll) loaded.\n");
            break;

        case DLL_THREAD_ATTACH:
            // Runs when a new thread is created in the process.
            break;

        case DLL_THREAD_DETACH:
            // Runs when a thread exits cleanly.
            break;

        case DLL_PROCESS_DETACH:
            // Runs when the DLL is unloaded from the process.
            printf("[-] Test DLL (test.dll) unloaded.\n");
            break;
    }
    return TRUE; // Successful.
}

DLLEXPORT HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
    // Display a message box when this function is called.
    MessageBox(NULL, "DllGetClassObject was called!", "Exported Function", MB_OK);

    printf("[+] DllGetClassObject in test.dll was called!\n");

    // We are not implementing a real COM object, so we set the output pointer to NULL.
    *ppv = NULL;

    // Return a standard COM error indicating that we don't have the requested class.
    return CLASS_E_CLASSNOTAVAILABLE;
}
