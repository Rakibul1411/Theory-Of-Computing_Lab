#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10
#define ALPHABET_SIZE 2
int path[100];
int transition[MAX_STATES][ALPHABET_SIZE][MAX_STATES];
bool isAccepting[MAX_STATES];

bool simulateNFA(char *input, int index, int state, int numStates, int pathIndex) {
    if (input[index] == '\0') {
        path[pathIndex] = state;
        return isAccepting[state];
    }

    int symbol = input[index] - '0';
    for (int i = 0; i < numStates; i++) {
        if (transition[state][symbol][i] != -1) {
            path[pathIndex] =state;
            if (simulateNFA(input, index + 1, transition[state][symbol][i], numStates, pathIndex + 1)) {
                return true;
            }
        }
    }

   // path[pathIndex] = '\0';
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
        //char in = 'a';
        printf("For State q%d ", i);
        //++in;
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

    //char path[100];
    if (simulateNFA(input, 0, 0, numStates, 0)) {
        printf("Accepted! \n");
    } else {
        printf("Rejected!\n");
    }
    int len=0;
    for (int i = 0; i < input[i] !='\0'; ++i) {
        ++len;
    }
    printf("Path is: ");
    int sym=0;
    for (int i = 0; i <= len; ++i) {
        printf("%d", path[i]);
        if(sym != len){
            printf("=>");
        }
        ++sym;
    }
    return 0;
}
