
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int l;
    //char st[5][l];
    for (int i = 0; i < 5; ++i) {
        l = rand()%100;
        char st[5][l];
        printf("%ld\n", l);
        for ( int j = 0; j < l; ++j) {
            if (j%2==0){
                st[i][j] = '1';
            }
            else {
                st[i][j] ='0';
            }
        }
        st[i][l]='\0';

        printf("....................................\n");

        int a=0;
        printf("%s\n", st[i]);
        for (int j = 0; j < l; ++j) {
            if(st[i][j] =='0' || st[i][j]=='1')
                a++;
        }
        printf("%d\n\n", a);
    }

    return 0;
}
