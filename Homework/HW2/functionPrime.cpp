#include <iostream>
#include <cmath>

using namespace std;

void isPrime(int n){
    int x = 0;
    for(int i = 2; i < n; i++){
        x = n % i;
        if(x == 0){
            cout << "The number " << n << " isn't prime";
            return;
        }
    }
    cout << "The number " << n << " is prime";
}
