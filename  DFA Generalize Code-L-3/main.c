#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool processInput( char* input,int startState, int finalState, int transitions[][2]) {
    int currentState = startState;
    char symbol;
    int len = strlen(input);
    int path[len+1];
    path[0] = currentState;
    printf("Path is:- %d ", path[0]);
    int i=1;
    while (*input != '\0') {
        symbol = *input;

        if (symbol != '0' && symbol != '1') {
            return false; // Reject if the input symbol is not '0' or '1'
        }

        currentState = transitions[currentState][symbol - '0'];
       path[i] = currentState;
        printf("%d ", path[i]);
        if (currentState == -1) {
            return false; // Reject if no transition defined for the current state and input symbol
        }
        ++i;
        input++;
    }

    printf("\n");
    return (currentState == finalState);
}

int main() {
    int numStates, startState, finalState, numAlphabet;

    printf("Enter the number of states: ");
    scanf("%d", &numStates);
    printf("Enter the number of alphabet: ");
    scanf("%d", &numAlphabet);
    int transitions[100][numAlphabet];
    printf("Enter the transitions (use -1 for invalid transitions):\n");
    for (int i = 0; i < numStates; i++) {
        printf("State %d, Transition (0): ", i);
        scanf("%d", &transitions[i][0]);
        printf("State %d, Transition (1): ", i);
        scanf("%d", &transitions[i][1]);
    }

    printf("Enter the start state: ");
    scanf("%d", &startState);

    printf("Enter the final state: ");
    scanf("%d", &finalState);

    char inputString[100];
    printf("Enter the input string containing '0' and '1': ");
    scanf("%s", inputString);

    bool isAccepted = processInput(inputString, startState, finalState, transitions);

    if (isAccepted)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
