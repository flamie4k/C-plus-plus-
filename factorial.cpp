#include <iostream>
using namespace std;
int main(){
    int x;
    printf("Enter the a number :");
    scanf("%d",&x);
    int result = 1;
    for (int i = 1; i<x; i++){
        result = result * i;
    }
    printf("\nThe factorial of %d is %d . ",x,result);

    cout<<powah(2,4);

}
int powah(int x, int y){
    int result = 1;
    result  = x ^ y;
    return result;
}