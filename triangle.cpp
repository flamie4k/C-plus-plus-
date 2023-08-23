#include <iostream>
using namespace std;
class triangle{
    private:
    int a,b,c,d;
    int s;
    int area;
    public:
    triangle(){
        cout<<"Enter the three sides respectively : "<<endl;
        cin>>a>>b>>c;
    }
    triangle (int x){
        s = (a/2)+(b/2)+(c/2);
        d = (s*(s - a)*(s - b)*(s - c))^(1/2);
    }

    int display(){
        cout<<"Area is of the triangle is: "<<d<<endl;
        return 0;
    }
};
int main(){
    triangle t1, t2 (0);
    t2.display();
}