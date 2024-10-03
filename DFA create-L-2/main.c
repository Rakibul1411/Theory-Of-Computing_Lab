#include <stdio.h>

int main() {
    printf("Enter the string: ");
    char str[100];
    scanf("%s", str);
    char state = 'A';
    printf("Visiting state are: ");
    for (int i = 0; str[i] != '\0' ; ++i) {
        switch (state) {
            case 'A':
                if(str[i] == '0'){
                    state = 'B';
                    printf("%c ", state);
                } else{
                    state = 'A';
                    printf("%c ", state);
                }
                break;

            case 'B':
                if(str[i] == '0'){
                    state = 'C';
                    printf("%c ", state);
                } else{
                    state = 'A';
                    printf("%c ", state);
                }
                break;

            case 'C':
                if(str[i] == '0'){
                    state = 'C';
                    printf("%c ", state);
                } else {
                    state = 'A';
                    printf("%c ", state);
                }
                break;
        }
    }
    printf("\n");
    if(state == 'C'){
        printf("The string is formed by this DFA");
    }
    else{
        printf("The string is not formed by this DFA");
    }
    return 0;
}
