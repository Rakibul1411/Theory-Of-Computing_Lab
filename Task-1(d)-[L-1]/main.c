#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int a = rand()%100;
    int b = rand()%100;
    printf("Maximum size of string x= %d\n", a);
    printf("Maximum size of string y= %d\n", b);

    printf("Enter the two string:-- \n");
    char x[a];
    char y[b];
    printf("String X is = ");
    scanf("%s", x);
    printf("String Y is = ");
    scanf("%s", y);
    int l1=0, l2=0;
    for (int i = 0; x[i] !='\0' ; ++i) {
        ++l1;
    }
    for (int i = 0; y[i] !='\0' ; ++i) {
        ++l2;
    }
    int l = l1+l2;
    char z[l+1];
    for (int i = 0; x[i] !='\0' ; ++i) {
        z[i] = x[i];
    }
    for (int i = 0; y[i] !='\0' ; ++i) {
        z[l1] = y[i];
        ++l1;
    }
    z[l] = '\0';
    printf("Concatenated String is:- ");
    printf("%s\n", z);
    return 0;
}
