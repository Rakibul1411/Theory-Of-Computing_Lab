#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char arr[100];

int CheckPal(char string[],int start,int end){
    printf("=>%s",arr);
    if(start > end){
        for(int i=start;i<strlen(arr);i++){
            arr[i]=arr[i+1];
        }

        return 1;
    }

    else if(start == end){
        if(string[start]=='0'){
            //printf("0");
            arr[start]='0';
        }
        else if(string[start] == '1'){
            // printf("1");
            arr[start]= '1';
        }

        return 1;

    }
    else if(string[start]=='0' && string[end]=='0'){
        //printf("0P0");
        for(int i=strlen(arr)+1;arr[i-2]!='P';i--){
            arr[i]=arr[i-2];
        }
        arr[start]='0';
        arr[start+1]='P';
        arr[start+2]='0';
        return CheckPal(string,start+1,end-1);
    }
    else if(string[start]=='1' && string[end]=='1'){
        //printf("1P1");
        for(int i=strlen(arr)+1;arr[i-2]!='P';i--){
            arr[i]=arr[i-2];
        }
        arr[start]='1';
        arr[start+1]='P';
        arr[start+2]='1';
        return CheckPal(string,start+1,end-1);
    }

    else{
        printf("\n\nNot in this grammer\n");
        exit(0);
    }

}
int main(){
    char string[100];
    printf("Enter the string: ");
    scanf("%s",string);
    arr[0]='P';
    CheckPal(string,0,strlen(string)-1);
    printf("=>%s",arr);
    return 0;
}