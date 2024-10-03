#include <stdio.h>

int main() {
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    int len=0;
    for (int i = 0; str[i] != '\0' ; ++i) {
        ++len;
    }
    int temp=0;
    for (int i = 0; i < len/2; ++i) {
        if(str[i] == str[len-1]){
            temp=0;
        } else{
            temp=1;
            break;
        }
        --len;
    }
   if(temp==0){
       printf("The given string is palindrome");
   }
   else
   {
       printf("The given string is not a prlindrome");
   }

    return 0;
}
