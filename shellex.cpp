//You have to use the path to the main .exe of a program in wchat_t* G_Loaction. The wchat_t* G_name is not the path.
//Also this program is NOT complete
#include <iostream>
#include <windows.h>
#include <cstring>
#include <vector>

int launch(const wchar_t* G_Location, const wchar_t* G_name){
  int result = (int)ShellExecuteW(NULL, L"open", G_Location,NULL, NULL, SH_SHOWNORMAL);
  if (result> = 32){
    std::cerr("Error launching "<<G_name<<"."<<std::endl;
}
int main(){
  const
