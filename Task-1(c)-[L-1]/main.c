#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int l;
    l = rand()%100;
    char in[l];
    printf("Enter the string and string length not exceeded:- %d\n", l);
    printf("Enter the string :- ");
    scanf("%s", in);
    int temp=0;
    for (int i = 0; in[i] !='\0'; ++i) {
        if(in[i]=='0' || in[i]=='1') {
            temp = 0;
        }
        else if(in[i] !='0' || in[i] !='1'){
            temp=1;
            break;
        }
    }
    if(temp==1){
        printf("The user input string doesn't form by the given alphabet");
    } else{
        printf("The user input string form by the given alphabet");
    }

    return 0;
}
