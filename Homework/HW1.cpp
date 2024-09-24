#include <iostream>
#include <cmath>
using namespace std;


int sumUpTo(int n){
    int x = 0;
    for(int i = 0; i <= n; i++){    
        x = x + i;
    }
    return x;
}

double sumReciprocalNormal(int n){
    double x = 0.0;
    for(int i = 1; i <= n; i++){
        x = x + (1.0/i);
    }
    return x;

}

double sumReciprocalRev(int n){
    double x = 0.0;
    for(int i = 100; i > 0; i--){
        x = x + (1.0/i);
    }
    return x;

}

double sumMulReciprocalsNormal(int n){
    double x = 0.0;
    for(int i = 1; i <= n; i++){
        x = x + (1.0/(i*i));
    }
    return x;

}

double sumMulReciprocalsRev(int n){
    double x = 0.0;
    for(int i = 100; i > 0; i--){
        x = x + (1.0/(i*i));
    }
    return x;

}

int main() {
// Problem One
cout << "The sum of all numbers up to 100 is: " << sumUpTo(100) << '\n';


// Problem Two
cout << "The sum of all reciprocals up to 100 is: " << sumReciprocalNormal(100) << '\n';
cout << "The sum of all reciprocals down from 100 is: " << sumReciprocalRev(100) << '\n';


// Problem Three
cout << "The sum of all multiplication reciprocals up to 100 is: " << sumMulReciprocalsNormal(100) << '\n';
cout << "The sum of all multiplication reciprocals down from 100 is: " << sumMulReciprocalsRev(100) << '\n';


return 0;
}
