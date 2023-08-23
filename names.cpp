#include <iostream>
#include <string>

using namespace std;

class name{
    protected:
    string f_name;
    string l_name;
    string full_name;
    public: 
    name(){
        cout<<"Enter youf first name : ";
        cin>>f_name;
        cout<<endl;
    }
    name(int x){
        x = 0;
        cout<<"Enter your last name : ";
        cin>>l_name;
   }
   string display(){
        f_name.append(l_name);
        cout<<f_name<<" ";
   }
};
int main(){
    name n1;
    name n2(1);
    n1.display();
    n2.display();
}
