#include <iostream>
using namespace std;

class one{
    protected:
    char name[10] = "Pittu";
    char address[20] = "Lutputpur";
    public:
    void  showone(){
        printf("Name is %s \n", name);
        cout<<"Address is : "<<address<<endl;
    }
};
class two{
    protected:
    int age = 20;
    char hammer[5] = "400%";
    public:
    void showtwo(){
        cout<<"Age is "<<age<<endl;
        cout<<"Hammer capacity is : "<<hammer<<endl;
    }
};
class three : public one, public two{
    public: 
    void showthree(){
        cout<<"This is from class three. "<<endl;
        for (int i = 0; i<5; i++){
            printf("Lutputgiri ko baato ma lagau");
            cout<<endl;
        }
    }
};
int main(){
    three t;
    t.showone();
    t.showtwo();
    t.showthree();
}
