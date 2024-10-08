#include <stdio.h>
#include <stdbool.h>

#define NUM_STATES 8
#define NUM_SYMBOLS 2

char states[NUM_STATES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
//char alphabet[NUM_SYMBOLS] = {'0', '1'};
char transition[NUM_STATES][NUM_SYMBOLS] = {{'B', 'A'}, {'A', 'C'}, {'D', 'B'}, {'D', 'A'}, {'D', 'F'}, {'G', 'E'}, {'F', 'G'}, {'G', 'D'}};
char table[NUM_STATES][NUM_STATES];
char finalStates[NUM_STATES] = {'D'};
char equivalentStates[NUM_STATES][2];

int equivCount = 0;

void initializeTable() {
    for(int i = 0; i < NUM_STATES; i++) {
        for(int j = 0; j <= i; j++) {   // j < NUM_STATES
            if(i==j){
                table[i][j] = '=';
            }
            else {
                table[i][j] = '-';
            }
        }
    }
}

void markFinalStates() {
    for(int i = 0; i < NUM_STATES; i++) {
        for(int j = 0; j < i; j++) {  // j < NUM_STATES
            if((states[i] == finalStates[0] && states[j] != finalStates[0]) || (states[i] != finalStates[0] && states[j] == finalStates[0])) {
                table[i][j] = 'X';
            }
        }
    }
}

void findEquivalences() {
    for(int i = 0; i < NUM_STATES; i++) {
        for(int j = 0; j < i; j++) {
            if(table[i][j] == '-') {
                bool equivalent = true;
                for(int k = 0; k < NUM_SYMBOLS; k++) {
                    char nextState1 = transition[i][k];
                    char nextState2 = transition[j][k];
                    int stateIndex1, stateIndex2;
                    for(int m = 0; m < NUM_STATES; m++) {
                        if(states[m] == nextState1) {
                            stateIndex1 = m;
                        }
                        if(states[m] == nextState2) {
                            stateIndex2 = m;
                        }
                    }
                    if(table[stateIndex1][stateIndex2] == 'X' || table[stateIndex2][stateIndex1] == 'X') {
                        equivalent = false;
                        break;
                    }
                }
                if(equivalent) {
                    table[i][j] = '=';
                   // table[j][i] = '=';

                    equivalentStates[equivCount][0] = states[i];
                    equivalentStates[equivCount][1] = states[j];
                    equivCount++;
                } else {
                    table[i][j] = 'X';
                    table[j][i] = 'X';
                }
            }
        }
    }
}

void printTable() {
    printf("\nTable of distinguish:\n");


//    printf("  ");
//    for(int i = 0; i < NUM_STATES; i++) {
//        printf("%c ", states[i]);
//    }
//    printf("\n");

    for(int i = 0; i < NUM_STATES; i++) {

        printf("%c ", states[i]);

        for(int j = 0; j < i+1; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for(int i = 0; i < NUM_STATES; i++) {
        printf("%c ", states[i]);
    }
}

void printEquivalentStates() {
    printf("\nEquivalent states:\n");
    for(int i = 0; i < equivCount; i++) {
        printf("%c = %c\n", equivalentStates[i][0], equivalentStates[i][1]);
    }
}

int main() {
    initializeTable();
    markFinalStates();
    findEquivalences();
    printTable();
    printEquivalentStates();
    return 0;
}


