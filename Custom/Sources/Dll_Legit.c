#include <windows.h>
#include <objbase.h> // Required for COM interfaces and HRESULT
#include <stdio.h>

// Define DLLEXPORT for easy export syntax
#define DLLEXPORT __declspec(dllexport)

// DllMain: The standard entry point for a DLL.
// It's called by the system when the DLL is loaded or unloaded.
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

// DllGetClassObject: A standard COM function that provides a class factory.
// This implementation is a stub. It prints a message and returns an error.
// The function signature MUST match the one defined in the Windows headers.
//
// HRESULT: The return type, a standard COM error/success code.
// REFCLSID rclsid: The Class ID (CLSID) of the object to create.
// REFIID riid: The Interface ID (IID) being requested.
// LPVOID *ppv: A pointer to receive the interface pointer.
//
DLLEXPORT HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv) {
    // Display a message box when this function is called.
    MessageBox(NULL, "DllGetClassObject was called!", "Exported Function", MB_OK);

    printf("[+] DllGetClassObject in test.dll was called!\n");

    // We are not implementing a real COM object, so we set the output pointer to NULL.
    *ppv = NULL;

    // Return a standard COM error indicating that we don't have the requested class.
    // This is a safe and valid response for a stub function.
    return CLASS_E_CLASSNOTAVAILABLE;
}
