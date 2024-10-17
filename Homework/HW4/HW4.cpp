
#include <time.h>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
// complete the JulianDate class
// write your code in the JulianDae class
// complete the code in main
class JulianDate {
// Make all your class access is public
public:
// first define your variable type and variable (year, month, day, hour, mins, sec)
int year, month, day, hour, mins, sec;
// write your non-default constructor that set variables today's date
// write your code here

JulianDate(int y, int m, int d, int h, int min, int s) : 
year(y), month(m), day(d), hour(h), mins(min), sec(s) {}
// Name it JulianDate

JulianDate(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    hour = ltm->tm_hour;
    mins = ltm->tm_min;
    sec = ltm->tm_sec;

}

// Write your default constructor that takes nothing
// write function that calculate julian number from given date
// your function should return the value
// use calc_juliandate as the function name
// write your code here

double calc_juliandate(){
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a -3;

    int JDN = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

    double jd_frac = (hour - 12) / 24.0 + mins / 1440.0 + sec / 86400.0;

    return JDN + jd_frac;
}


// write function that calculate difference between two Julian date
// use diff_calc_juliandate as the function name
// write your code here

double diff_calc_juliandate(JulianDate other) {
    return fabs(this->calc_juliandate() - other.calc_juliandate());
}

};
/*
Use the formula in the below web page in the calculate julian function
http://www.c-jump.com/bcc/c155c/Homework/a4_Serial_Julian_Date/
a4_Serial_Julian_Date.html
https://www.aavso.org/jd-calculator
hh:mm:ss
00:00:00 0.0
12:00:00 0.5
18*365+18/4 - 18/100 + 18/400
18*364+4 = 6574
6574.041666666 --> Jan 1, 2018, 01:00:00
*/
//int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0
int main() {
cout << "########" << endl;
cout << "Main Problem" << endl;
cout << "########" << endl;
// Run your class on this code and calculate the difference of Julian number below
cout.precision(20);
JulianDate x(2007, 2, 8, 0, 0, 0); // how many days since day 0? dy = (2018 -2000) * 365
double x1 = x.calc_juliandate();
cout << x1 << endl;
JulianDate y(2000, 12, 31, 0, 0, 1);
double y1 = y.calc_juliandate();
cout << y1 << endl;
cout << "\n";
//manual calculation of the difference between two dates, e.g., x1 - y1 = results
//print out the result
// write your code here

double manual_diff = x1 - y1;
cout << "Manual difference between x1 and y1: " << manual_diff << endl;

// Now use your class function to find the difference between two dates
// print out the result
// write your code here

double class_diff = x.diff_calc_juliandate(y);
cout << "Difference using class function: " << class_diff << endl;

//example of date to Julian date format without hour/min/sec
//7/4/1776 2369916
//12/31/2000 2451910
//2/8/2007 2454140
//2/9/2007 2454141
cout << "====[ end ]====" << endl;
return 0;
}
