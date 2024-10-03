#include <iostream>
using namespace std;
int main() {
    int numStates;
    cout << "Enter the no of states: ";
    cin >> numStates;
    int numAlpha;
    cout<< "Enter the no of alphabet: ";
    cin >> numAlpha;

    cout<< "Enter the symbols of alphabets: ";
    int alpha[numAlpha];
    for (int i = 0; i < numAlpha; ++i) {
        cin >> alpha[i];
    }
    int transition[numStates+1][numAlpha][numStates+1];
    int symbol[numStates+1][numStates+1];
    cout<< "Enter the transition table: ";
    for (int i = 1; i <= numStates; ++i) {
        for (int j = 0; j < numAlpha; ++j) {
            for (int k = 1; k <=numStates ; ++k) {
                cin >> transition[i][j][k];
                if(transition[i][j][k]){
                    symbol[i][k] = j;
                } else{
                    symbol[i][k] = -1;
                }
            }
        }
    }

    for (int i = 1; i <=numStates ; ++i) {
        for (int j = 1; j <=numStates ; ++j) {
            if(symbol[i][j] ==1){
                if(i==j){
                    cout<<"R["<<i<<"]"<<"["<<j<<"]" << symbol[i][j]<<"+"<<"e"<<endl;
                }
                else{
                    cout<<"R["<<i<<"]"<<"["<<j<<"]" <<symbol[i][j]<<endl;
                }
            }
            else if(symbol[i][j] == 0){
                if(i==j){
                    cout<<"R["<<i<<"]"<<"["<<j<<"]" << symbol[i][j]<<"+"<<"e"<<endl;
                }
                else{
                    cout<< "R["<<i<<"]"<<"["<<j<<"]" <<symbol[i][j]<<endl;
                }
            }
            else if(symbol[i][j] == -1){
                if(i==j){
                    cout<< "R["<<i<<"]"<<"["<<j<<"]" <<"e"<< endl;
                } else{
                    cout<< "R["<<i<<"]"<<"["<<j<<"]" <<"$"<< endl;
                }
            }
        }
    }
    for (int i = 1; i <=numStates ; ++i) {
        for (int j = 1; j <=numStates ; ++j) {
            cout<< symbol[i][j]<<" ";
        }
    }
    return 0;
}