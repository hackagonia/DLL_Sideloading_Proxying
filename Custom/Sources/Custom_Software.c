#include <windows.h>

typedef PCHAR(*fnRetStr)();

int main(){
    HMODULE  hLegitDll = LoadLibraryA("Dll_Legit.dll");
    fnRetStr pRetStr   = (fnRetStr)GetProcAddress( hLegitDll, "DllGetClassObject" ); 
    PCHAR    Str       = pRetStr();
    
    printf(Str);

}
