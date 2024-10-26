#include <iostream>
using namespace std;

double pow(double x, int n){
    double result = 1.0;

    bool negative = n < 0;

    for (int i = 0; i < abs(n); i++){
        result *= x; 
    }
    return negative ? 1.0/result : result;
}

int main(){
    double x;
    int n;
    cout << "Base: ";
    cin >> x;
    cout << "Exp: ";
    cin >> n;

    double result = pow(x, n);
    cout << x << "^" << n << " = " << result << std::endl;
}