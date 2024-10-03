#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10
#define ALPHABET_SIZE 2

int transition[MAX_STATES][ALPHABET_SIZE][MAX_STATES];
bool isAccepting[MAX_STATES];

bool simulateNFA(char *input, int index, int state, int numStates, char *path, int pathIndex) {
    if (input[index] == '\0') {
        path[pathIndex] = '\0';
        return isAccepting[state];
    }

    int symbol = input[index] - '0';
    for (int i = 0; i < numStates; i++) {
        if (transition[state][symbol][i] != -1) {
            path[pathIndex] = '0' + symbol;
            if (simulateNFA(input, index + 1, transition[state][symbol][i], numStates, path, pathIndex + 1)) {
                return true;
            }
        }
    }

    path[pathIndex] = '\0';
    return false;
}

int main() {
    int numStates;

    printf("Enter the number of states: ");
    scanf("%d", &numStates);

    int numAcceptingStates;

    printf("Enter the number of accepting states: ");
    scanf("%d", &numAcceptingStates);

    printf("Enter the accepting states:\n");
    for (int i = 0; i < numAcceptingStates; i++) {
        int acceptingState;
        scanf("%d", &acceptingState);
        isAccepting[acceptingState] = true;
    }

    for (int i = 0; i < MAX_STATES; i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            for (int k = 0; k < MAX_STATES; k++) {
                transition[i][j][k] = -1;
            }
        }
    }

    printf("Enter transition details (use -1 for no transition):\n");
    for (int i = 0; i < numStates; i++) {
        printf("For State q%d ", i);
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            printf("transition on input %d to states: ", j);
            for (int k = 0; k < numStates; k++) {
                scanf("%d", &transition[i][j][k]);
            }
        }
    }

    char input[100];
    printf("Enter a binary string: ");
    scanf("%s", input);

    char path[100];
    if (simulateNFA(input, 0, 0, numStates, path, 0)) {
        printf("Accepted! ");
    } else {
        printf("Rejected!\n");
    }

    return 0;
}
