#include <iostream> 
using namespace std;
class B;
class A{
    private: 
    int numA;
    public: 
    A() : numA(12){}
    friend int add(A, B);
};
class B {
    private: 
    int numB;
    public: 
    B() : numB(12){}
    friend int add(A, B);
};
int add(A awan, B bwan){
    return(awan.numA + bwan.numB);
}
int main(){
    A awan;
    B bwan;
    cout<<"Sum : "<<add(awan,bwan)<<endl;
}