#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;

// Function to print the NFA transition table
void printNFA(vector<vector<vector<int>>> nfaTable) {
    cout << "  STATES ";
    char inputSymbol = 'a';

    for (int i = 0; i < nfaTable[0].size() - 1; i++) {
        cout << "   " << inputSymbol++ << "   ";
    }

    cout << "   ^   " << endl << endl;

    for (int i = 0; i < nfaTable.size(); i++) {
        cout << "       " << i << "      ";

        for (int j = 0; j < nfaTable[i].size(); j++) {
            cout << " | ";

            for (int k = 0; k < nfaTable[i][j].size(); k++) {
                cout << nfaTable[i][j][k] << " ";
            }
        }

        cout << endl;
    }
}

// Function to print the DFA transition table
void printDFA(vector<vector<int>> dfaStates, vector<vector<vector<int>>> dfaTable) {
    cout << "  STATES  ";
    char inputSymbol = 'a';

    for (int i = 0; i < dfaTable[0].size(); i++) {
        cout << "|   " << inputSymbol++ << "   ";
    }

    cout << endl;

    for (int i = 0; i < dfaStates.size(); i++) {
        cout << "{ ";

        for (int h = 0; h < dfaStates[i].size(); h++)
            cout << dfaStates[i][h] << " ";

        if (dfaStates[i].empty()) {
            cout << "^ ";
        }

        cout << "} ";

        for (int j = 0; j < dfaTable[i].size(); j++) {
            cout << " | ";

            for (int k = 0; k < dfaTable[i][j].size(); k++) {
                cout << dfaTable[i][j][k] << " ";
            }

            if (dfaTable[i][j].empty()) {
                cout << "^ ";
            }
        }

        cout << endl;
    }
}

// Function to compute the epsilon closure of a state in the NFA
vector<int> epsilonClosure(int state, vector<vector<vector<int>>> nfaTable) {
    vector<int> closureSet;
    queue<int> q;
    closureSet.push_back(state);

    int numTransitions = nfaTable[state][nfaTable[state].size() - 1].size();

    for (int i = 0; i < numTransitions; i++) {
        closureSet.push_back(nfaTable[state][nfaTable[state].size() - 1][i]);
        q.push(closureSet[i]);
    }

    while (!q.empty()) {
        int frontElement = q.front();
        q.pop();

        if (!nfaTable[frontElement][nfaTable[frontElement].size() - 1].empty()) {
            int numEpsilonTransitions = nfaTable[frontElement][nfaTable[frontElement].size() - 1].size();

            for (int i = 0; i < numEpsilonTransitions; i++) {
                int nextEpsilonState = nfaTable[frontElement][nfaTable[frontElement].size() - 1][i];

                if (find(closureSet.begin(), closureSet.end(), nextEpsilonState) == closureSet.end()) {
                    closureSet.push_back(nextEpsilonState);
                    q.push(nextEpsilonState);
                }
            }
        }
    }

    return closureSet;
}

int main() {
    int numStates, numInputSymbols;
    cout << "Enter the total number of states in NFA: ";
    cin >> numStates;

    cout << "Enter the number of elements in the alphabet: ";
    cin >> numInputSymbols;

    vector<vector<vector<int>>> nfaTransitionTable;

    for (int i = 0; i < numStates; i++) {
        cout << "For state " << i << endl;

        vector<vector<int>> transitions;
        char inputSymbol = 'a';
        int outputState, numOutputStates;

        for (int j = 0; j < numInputSymbols; j++) {
            vector<int> transitionSet;
            cout << "Enter the number of output states for input " << inputSymbol++ << " : ";
            cin >> numOutputStates;

            cout << "Enter output states:" << endl;

            for (int k = 0; k < numOutputStates; k++) {
                cin >> outputState;
                transitionSet.push_back(outputState);
            }

            transitions.push_back(transitionSet);
        }

        vector<int> epsilonTransitionSet;
        cout << "Enter the number of output states for epsilon (^): ";
        cin >> numOutputStates;
        cout << "Enter output states:" << endl;

        for (int k = 0; k < numOutputStates; k++) {
            cin >> outputState;
            epsilonTransitionSet.push_back(outputState);
        }

        transitions.push_back(epsilonTransitionSet);
        nfaTransitionTable.push_back(transitions);
    }

    cout << "TRANSITION TABLE OF NFA" << endl;
    printNFA(nfaTransitionTable);

    cout << endl << "TRANSITION TABLE OF DFA" << endl;

    vector<vector<vector<int>>> dfaTransitionTable;
    vector<vector<int>> dfaStates;
    dfaStates.push_back(epsilonClosure(0, nfaTransitionTable));

    queue<vector<int>> queueStates;
    queueStates.push(dfaStates[0]);

    while (!queueStates.empty()) {
        vector<int> frontState = queueStates.front();
        queueStates.pop();

        vector<vector<int>> transitions;

        for (int i = 0; i < numInputSymbols; i++) {
            vector<int> transitionSet;
            set<int> uniqueStates;

            for (int j = 0; j < frontState.size(); j++) {
                for (int k = 0; k < nfaTransitionTable[frontState[j]][i].size(); k++) {
                    vector<int> epsilonClosureSet = epsilonClosure(nfaTransitionTable[frontState[j]][i][k], nfaTransitionTable);

                    for (int h = 0; h < epsilonClosureSet.size(); h++) {
                        if (uniqueStates.find(epsilonClosureSet[h]) == uniqueStates.end()) {
                            uniqueStates.insert(epsilonClosureSet[h]);
                        }
                    }
                }
            }

            for (set<int>::iterator iter = uniqueStates.begin(); iter != uniqueStates.end(); iter++) {
                transitionSet.push_back(*iter);
            }

            transitions.push_back(transitionSet);

            if (find(dfaStates.begin(), dfaStates.end(), transitionSet) == dfaStates.end()) {
                dfaStates.push_back(transitionSet);
                queueStates.push(transitionSet);
            }
        }

        dfaTransitionTable.push_back(transitions);
    }

    printDFA(dfaStates, dfaTransitionTable);

    return 0;
}
