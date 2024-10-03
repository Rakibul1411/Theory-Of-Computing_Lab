#include <iostream>
#include <stack>

using namespace std;
int main() {
    stack<char> pda;
    int noSymbol;
    cout<<"Enter the no. of input symbol: ";
    cin>>noSymbol;
    char symbol[noSymbol];
    cout<< "Enter the symbol: ";
    for (int i = 0; i < noSymbol; ++i) {
        cin>> symbol[i];
    }
    string input;
    cout<<"Enter the Input string: ";
    cin>> input;
    for (int i = 0; i < input.size(); ++i) {
        if (symbol[i] == '(' || symbol[i] == '['){
            pda.push(input[i]);
        }
        else if(symbol[i] == ')' || symbol[i] == ']'){
            if(symbol[i] == ')')
               if(pda.top() == symbol[i]){
                  pda.pop();
               } else{
                  cout<<"Invalid";
                  break;
            }
            else if (symbol[i] == ']'){
                if(pda.top() == symbol[i]){
                    pda.pop();
                } else{
                    cout<<"Invalid";
                    break;
                }
            }
        }
    }
    if (pda.size() == 0){
        cout<< "Valid";
    }
    return 0;
}
