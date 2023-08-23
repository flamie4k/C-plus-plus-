#include <iostream>
using namespace std;

double divide(double dividend, double divisor) {
    if (divisor == 0) {
        throw "Division by zero is not allowed.";
    }
    return dividend / divisor;
}

int main() {
    double dividend, divisor;
    
    cout << "Enter dividend: ";
    cin >> dividend;
    
    cout << "Enter divisor: ";
    cin >> divisor;
    
    try {
        double result = divide(dividend, divisor);
        cout << "Result: " << result << endl;
    } catch (const char* error) {
        cout << "Error: " << error << endl;
    }
    
    return 0;
}