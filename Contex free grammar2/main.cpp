#include <iostream>
using namespace std;

string productions[] = {"e", "0", "1", "0P0", "1P1"};

bool hasProduction(string temp) {
    return (find(productions, productions + 5, temp) != productions + 5);
}

int findPIndex(string path) {
    int position = 0;
    for (int k = 0; k < path.size(); k++) {
        if ('P' == path[k]) {
            position = k;
        }
    }
    return position;
}

string replacePWithTemp(string path, string temp) {
    int position = findPIndex(path);
    return path.replace(position, 1, temp);
}

void generatePathString(string inputStr) {
    string temp, x, y, path = "P";
    cout << "P" << " => ";

    for (int i = 0, j = inputStr.size() - 1; i < j; i++, j--) {
        if (inputStr[i] != inputStr[j]) {
            cout << "Not in this grammar.";
            return;
        }

        x = inputStr[i];
        y = inputStr[j];
        temp = x + "P" + y;

        if (hasProduction(temp)) {
            path = replacePWithTemp(path, temp);
        }

        if (path == "p") {
            cout << "not" << endl;
            return;
        }
        cout << path << " => ";
    }
    cout << inputStr << endl;
}

int main() {
    string userString;
    cin >> userString;
    generatePathString(userString);
    return 0;
}