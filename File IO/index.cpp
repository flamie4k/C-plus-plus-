#include <iostream>
#include <Windows.h>
#define true 1
class Launcher {
public:
    void launch(const wchar_t* Path, const wchar_t* Name) {
        int result = (int)ShellExecuteW(NULL, L"open", Path, NULL, NULL, SW_SHOWNORMAL);
        if (result <= 32) {
            std::cerr << "Error launching " << Name << std::endl;
        }
    }
    void check(){
        FILE *fptr1, *fptr2, *fptr3;
        fptr1 = fopen("createfile.exe","r"); //Chechking if the compilation is done.
        fptr2 = fopen("writefile.exe","r");
        fptr3 = fopen("readfile.exe","r");
        if(fptr1==NULL || fptr2 == NULL || fptr3 == NULL){
            std::cout<<"Executables not found. Compiling now : "<<std::endl;
            system("gcc creatilefile.c -o createfile"); //recompiling all of them if something is missing, compilations don't duplicate at same location.
            system("gcc writefile.c -o writefile");
            system("gcc readfile.c -o readfile");
            //System() function from Windows API (Windows.h) allows C/C++ programs to run CMD prompts as arguments
        }
    }
};
int main(){
    Launcher L;
    L.check();
    int lib_var;
    L.launch(L"createfile.exe",L"FileCreate");  //L"<String>" is for wchar_t
    L.launch(L"writefile.exe",L"FileWrite");
    L.launch(L"readfile.exe",L"FileRead");
}


