#include <iostream>
using namespace std;
//Here, we make a constructor and destroy it using a destructor
class TA{
    public:
    TA(){
        cout<<"Constructor Activated. \n";
        cout<<" "<<endl;
    }
    ~TA(){
        cout<<"Destructor Activated. ";
    }
};
int main(){
    TA t;
}