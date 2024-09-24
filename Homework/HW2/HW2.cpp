#include <iostream>
#include <cmath> // double sin(double), double cos(double)
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
//#include "functionWind.h"
#include "functionPrime.cpp"
using namespace std;
// const for pi
const double pi = 3.14159265358979323846;

void windChill(){
    bool canRun = true;
    // define your input value and other variable
    // print out message to enter wind speed and take the input
    double w = 0;
    cout << "Enter Wind Speed(mph): ";
    cin >> w;
    // Check if speed meet condition
    if(w <= 3){
        bool canRun = false;
        cout << "Wind speed below 3 mph, cannot compute" << "\n";
        return;
    }else{
        bool canRun = true;
    }
    // print out message to enter temperature and take the input
    double t = 0;
    cout << "Enter Temp(F): ";
    cin >> t;
    // check if temperature meet condition
    if(t > 50){
        bool canRun = false;
        cout << "Temperature above 50 degrees F, cannot compute" << "\n";
        return;
    }else{
        bool canRun = true;
    }
    // check if all condition is met and use canRun to start calculation of wind
    //chill
    if(bool canRun = true){
        double x = 0;
        x = 35.74 + (0.6215 * t) - (35.75 * (pow(w, 0.16))) + ((0.4275 * t) * (pow(w, 0.16)));
        cout << "Wind Chill = " << x << "\n";
    }
}

int main() {
cout << "###########" << endl;
cout << "Problem One" << endl;
cout << "###########" << "\n" << endl;
// For problem one, you only need to write your code in "functionPrime.cpp"
//define isPrime
isPrime(19);
cout << '\n';
isPrime(81);// trial divide, 81%3 == 0 therefore not prime
cout << '\n';
isPrime(57) ; // 57 % 2, 57% 3, 57%4
cout << '\n';
cout << "====[ end ]====" << "\n" << "\n" << endl;
cout << "###########" << endl;
cout << "Problem Two" << endl;
cout << "###########" << "\n" << endl;
// For problem Two, you will need to write your code here
// first read file robotpath.dat and name it thefile by using ifstream
// make sure you use the full path to .dat file, e.g., .././src/robotpath.dat
//check if thefile exist or not

ifstream thefile; 
thefile.open("robotpath.dat");
double d,a,x,y,rad;

if (thefile.is_open()){
    cout << "File is open and ready" << '\n';
    cout << " " << '\n';
    while(thefile >> d){
        thefile >> a;
        rad = a * (pi/180);
        x = d * cos(rad);
        y = d * sin(rad);
        cout << setprecision(8) << "( " << x << " , " << y << " )" << "\n";
    }
}else{
    cout << "File not found!" << '\n';
    cout << " " << '\n';
}
thefile.close();

// define your variables each line r and theta from the polar coordinates
// use defined constant pi value in your calculation
// start reading file and do calculation
// while reading print the following for each line:
// - print distance and angle
// - print angle in radian, 1 degree is equal (pi/180degree)
// - print x and y location
// - check your conversion and print angle in rad after finding x and y with
//cartesian coordinates conversion
// don't forget to close your opened file

cout << "====[ end ]====" << "\n" << "\n" << endl;
cout << "###########" << endl;
cout << "Problem Three" << endl;
cout << "###########" << "\n" << endl;
//Write your code here
// use Boolean CanRun to decide to do calculation or not based on condition
windChill();
// print out the value
cout << "====[ end ]====" << endl;
return 0;
}