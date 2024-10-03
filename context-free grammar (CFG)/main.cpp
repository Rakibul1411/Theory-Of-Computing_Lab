#include <iostream>
#include <string>

using namespace std;

bool derivePalindrome(string input, int start, int end) {
    if (start > end) {
        return true;
    }

    if (start == end) {
        if (input[start] == '0') {
            cout << "0";
            return true;
        } else if (input[start] == '1') {
            cout << "1";
            return true;
        }
    }

    if (input[start] == '0' && input[end] == '0') {
        cout << "0P0 => ";
        if (derivePalindrome(input, start + 1, end - 1)) {
            cout << "0P0";
            return true;
        }
    } else if (input[start] == '1' && input[end] == '1') {
        cout << "1P1 => ";
        if (derivePalindrome(input, start + 1, end - 1)) {
            cout << "1P1";
            return true;
        }
    } else {
        cout << "Not in this grammar." << endl;
        return false;
    }
    return false;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    cout << "Output: P => ";
    if (input.length() > 0 && derivePalindrome(input, 0, input.length() - 1)) {
        cout << endl;
    } else {
        cout << "Not in this grammar." << endl;
    }

    return 0;
}
