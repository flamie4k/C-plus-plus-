#include <iostream>
#include <lutput.h>

//The method for recursion is written in lutput.h header file, at line no 46 to 53
/*The file path to the custom header file in Flamie's PC is C:\MinGW\lib\gcc\mingw32\6.3.0\include\c++
For other machines, just put the header file in your workstation directory*/
int main() {
   int x , i=0;
   std::cout << "Enter the number of terms of series : ";
   std::cin >> x;
   std::cout << "\nFibonnaci Series : ";
   while(i < x) {
      std::cout << " " << fib(i);
      i++;
   }
   return 0;
}