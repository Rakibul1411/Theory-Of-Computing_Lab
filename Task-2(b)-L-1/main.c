#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int len = rand()%100;
    printf("%d\n", len);
    int n;
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);
        int last = n-1;
        int first = 0;

        while (last > first) {
            if (str[first++] != str[last--]) {
                printf("%s is not a palindrome\n", str);
                return 0;
            }
        }

        printf("%s is a palindrome\n", str);

        return 0;
}
