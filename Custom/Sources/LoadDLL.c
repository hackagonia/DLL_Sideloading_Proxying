#include <windows.h>

typedef PCHAR(*fnRetStr)();

int main(){
    HMODULE  hLegitDll = LoadLibraryA("Mal.dll");
    fnRetStr pRetStr   = (fnRetStr)GetProcAddress( hLegitDll, "DllGetClassObject" ); 
    PCHAR    Str       = pRetStr();
    
    printf(Str);

}
