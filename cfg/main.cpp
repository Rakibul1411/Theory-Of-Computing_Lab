#include <iostream>
#include <string>

using namespace std;

bool derivePalindrome(string input, int start, int end) {
    if (start > end) {
        return true;
    }

    if (start == end) {
        if (input[start] == '0') {
            cout << "0" << endl;
            return true;
        } else if (input[start] == '1') {
            cout << "1" << endl;
            return true;
        } else {
            cout << "ε" << endl;
            return true;
        }
    }

    if (input[start] == '0' && input[end] == '0') {
        cout << "0P0 => ";
        return derivePalindrome(input, start + 1, end - 1);
    }

    if (input[start] == '1' && input[end] == '1') {
        cout << "1P1 => ";
        return derivePalindrome(input, start + 1, end - 1);
    }

    cout << "Not in this grammar." << endl;
    return false;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    cout << "P => ";
    if (derivePalindrome(input, 0, input.length() - 1)) {
        cout << input;
    }

    return 0;
}
