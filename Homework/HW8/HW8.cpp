#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    size_t length;

public:
    // Default Constructor
    String() : str(nullptr), length(0) {}

    // Non-Default Constructor
    String(const char* input){
        length = strlen(input);
        str = new char[length + 1];
        for(size_t i = 0; i < length; i++){
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    // Deconstruct
    ~String() {
        delete[] str;
    }

    // Copy constructor
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        for (size_t i = 0; i < length; ++i) {
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    // Move constructor
    String(String&& other) noexcept : str(other.str), length(other.length) {
        other.str = nullptr; 
        other.length = 0;
    }

    // Copy assignment operator
    String& operator=(const String& other) {
        if (this == &other) {
            return *this;
        }
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        for (size_t i = 0; i < length; ++i) {
            str[i] = other.str[i];
        }
        str[length] = '\0';
        return *this;
    }

    // Move assignment operator
    String& operator=(String&& other) noexcept {
        if (this == &other) {
            return *this; 
        }
        delete[] str; 
        str = other.str;
        length = other.length;
        other.str = nullptr; 
        other.length = 0;
        return *this;
    }

    // Overload + operator to concatenate strings
    String operator+(const String& other) const {
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];
        for (size_t i = 0; i < length; ++i) {
            newStr[i] = str[i];
        }
        for (size_t i = 0; i < other.length; ++i) {
            newStr[length + i] = other.str[i];
        }
        newStr[newLength] = '\0';
        return String(newStr);
    }

    // Overload << operator to print the string
    friend ostream& operator<<(ostream& os, const String& s) {
        if (s.str) {
            os << s.str;
        }
        return os;
    }
};

int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // Create String s = abc
    String s = "abc";
    // cout s
    cout << "s is: " << s << '\n';
    // Create String s = def
    String s2 = "def";
    // cout s2
    cout  << "s2 is: " << s2 << '\n';
    // create String s3 equal s2
    String s3 = s2; // copy constructor
    // cout s3
    cout << "s3 is: " << s3 << " copy constructor "<<'\n';
    //    Create String s4 that is assigned to s added to s2
    String s4 = s + s2;  // abcdef // copy constructor
    // cout s4
    cout << "s4 is: " << s4 << " copy constructor of s + s2"<< '\n';
    // Create s5 and move s4
    String s5 = move(s4); // move constructor
    // cout s5
    cout << "s5 is: " << s5 << '\n';
    cout << "cout s4 should give you error after move()" << endl;
    cout << s4 << '\n';
    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    return 0;
} 