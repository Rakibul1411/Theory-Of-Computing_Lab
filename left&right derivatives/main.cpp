#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> LeftmostDerivation(string inputString, int pivotIndex) {
    vector<string> leftTransitions;
    string current = "S";
    leftTransitions.push_back(current);

    if (current == "S") {
        leftTransitions.push_back("A1B");
        current = "A1B";
    }

    if (current == "A1B") {
        for (int i = 0; i < pivotIndex; i++) {
            leftTransitions.push_back("0" + leftTransitions.back());
        }

        current = leftTransitions.back();
        current.erase(current.begin() + current.find("A"));
        leftTransitions.push_back(current);

        current.erase(current.begin() + current.find("B"));

        for (int i = pivotIndex + 1; i < inputString.size(); i++) {
            if (inputString[i] == '0') {
                leftTransitions.push_back(current + "0B");
                current += "0";
            }
            else if (inputString[i] == '1') {
                leftTransitions.push_back(current + "1B");
                current += "1";
            }
        }

        current = leftTransitions.back();
        current.erase(current.begin() + current.find("B"));
        leftTransitions.push_back(current);
    }

    return leftTransitions;
}

vector<string> RightmostDerivation(string inputString, int pivotIndex) {
    vector<string> rightTransitions;
    string current = "S";
    rightTransitions.push_back(current);

    if (current == "S") {
        rightTransitions.push_back("A1B");
        current = "A1B";
    }

    if (current == "A1B") {
        current = "A1";

        for (int i = pivotIndex + 1; i < inputString.size(); i++) {
            if (inputString[i] == '0') {
                rightTransitions.push_back(current + "0B");
                current += "0";
            }
            else if (inputString[i] == '1') {
                rightTransitions.push_back(current + "1B");
                current += "1";
            }
        }

        current = rightTransitions.back();
        current.erase(current.begin() + current.find("B"));
        rightTransitions.push_back(current);

        for (int i = 0; i < pivotIndex; i++) {
            rightTransitions.push_back("0" + current);
            current = rightTransitions.back();
        }

        current = rightTransitions.back();
        current.erase(current.begin() + current.find("A"));
        rightTransitions.push_back(current);
    }

    return rightTransitions;
}

int main() {
    string inputString;
    cout << "Enter a string: ";
    cin >> inputString;

    int pivotIndex = inputString.find("1");

    vector<string> leftDerivation = LeftmostDerivation(inputString, pivotIndex);
    vector<string> rightDerivation = RightmostDerivation(inputString, pivotIndex);
    int i=0;
    cout << "Leftmost Derivation:\n";
    for (auto transition : leftDerivation) {
        cout << transition << " ";
    }
    cout << endl;
    cout << "Rightmost Derivation:\n";
    for (auto transition : rightDerivation) {
        cout << transition << " ";
    }

    return 0;
}
