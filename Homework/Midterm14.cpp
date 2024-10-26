#include <iostream>
#include <string>
using namespace std;

// Checks whether or not the input is a palindrome already
bool checkPali(const string& s, int i, int j) {
    while (i <= j) {
        // If the character at the beginning and end don't match its not a palindrome
        if (s[i] != s[j]) {
            return false;
        }
        // Iterates towards the center of the string on both ends
        i++;
        j--;
    }
    return true;
}

// Checks if the users input can become a palindrome
bool becomePali(const string& s) {
    // Pointers for the beginning and end of string
    int i = 0;
    int j = s.size() - 1;

    while (i <= j) {
        // If both of the letters are the same it continues to iterate through the string
        if (s[i] == s[j]) {
            i++;
            j--;
        } else {
            // If both characters are different it trys removing either the left character or the right character
            return checkPali(s, i + 1, j) || checkPali(s, i, j - 1);
        }
    }
    return true;  // Already a palindrome
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // Checks if the string can become a palindrome
    if (becomePali(s)) {
        // Check if the string is already a palindrome
        if (checkPali(s, 0, s.size() - 1)) {
            cout << "The string is a palindrome." << endl;
        } else {
            cout << "The string can become a palindrome by deleting at most one character." << endl;
        }
    } else {
        cout << "The string cannot become a palindrome by deleting at most one character." << endl;
    }

    return 0;
}
