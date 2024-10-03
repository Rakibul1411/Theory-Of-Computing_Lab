#include <stdio.h>

int main() {
    int put_alphabet_numbers;
    scanf("%d", &put_alphabet_numbers);
    int n=1;
    int store[put_alphabet_numbers];
    for (int i = 0; i <put_alphabet_numbers ; ++i) {
       n= n*2;
       store[i]=0;
    }
    for (int i = 0; i < n; ++i) {
        int a=i;
        for (int j = 0; a > 0 ; ++j) {
                store[j]=(a%2);
                a = a/2;
        }
        for (int j = put_alphabet_numbers-1; j >=0 ; --j) {
            printf("%d", store[j]);
        }
        printf("\n");
    }
    return 0;
}
