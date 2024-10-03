#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<conio.h>
int main(){
    int n,inputNum;
    FILE *fp = fopen("Input.txt","r");
    if(fp == NULL){
        printf("Error. Can't open file.");
        exit(1);
    }
    fscanf(fp,"%d%d",&n,&inputNum);
    printf("%d\t",n);
    char Alphabet[inputNum+1];
    for(int i=1;i<=inputNum;i++){
        fgetc(fp);
        Alphabet[i] = fgetc(fp);
    }
    printf("%c %c",Alphabet[1],Alphabet[2]);
    int dfa[n+1][inputNum+1];
    char R[n+1][n+1][n+1][10];



    for(int i=1;i<=n;i++){
        for(int j=1;j<=inputNum;j++){
            fscanf(fp,"%d",&dfa[i][j]);
        }
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=inputNum;j++){
            printf("%d\t",dfa[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            strcpy(R[0][i][j],"\0");
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int flag=0;
            if(i == j ){
                strcat(R[0][i][j],"e");
                flag=1;
            }
            for(int k=1;k<=inputNum;k++){
                if(dfa[i][k] == j){
                    if(flag==1){
                        strcat(R[0][i][j],"+");
                    }
                    char str[]={Alphabet[k],'\0'};
                    strcat(R[0][i][j],str);
                    flag=1;
                }

            }
            if(flag==0){
                strcpy(R[0][i][j],"@");
            }
            /*  if(j<=inputNum){
              if(i == dfa[i][j]){
                  char str[]= {'+',Alphabet[j],'\0'};
                  //if( R[0][i][dfa[i][j]] )
                      strcat(R[0][i][dfa[i][j]],str);
                  else
                      strc(R[0][i][dfa[i][j]],str);


              }



              else{
                  char str[]= {Alphabet[j],'\0'};
                  strcpy(R[0][i][dfa[i][j]],str);
              }
              }*/

        }
    }
    printf("\n\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if( !strcmp(R[0][i][j], "\0")){
                strcpy(R[0][i][j],"@");
            }

            printf("R[0][%d][%d] %s\n",i,j,R[0][i][j]);

        }

    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                strcpy(R[k][i][j],"(");

                strcat(R[k][i][j],R[k-1][i][j]);


                strcat(R[k][i][j],")+(");
                strcat(R[k][i][j],R[k-1][i][k]);
                strcat(R[k][i][j],"(");

                strcat(R[k][i][j],R[k-1][k][k]);

                strcat(R[k][i][j],")*(");

                strcat(R[k][i][j],R[k-1][k][j]);

                strcat(R[k][i][j],")");
            }
        }
        printf("For k = %d\n",k);
        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){
                printf("R[%d][%d] :%s\n",i,j,R[k][i][j]);
            }
        }
        printf("\n\n");
    }
    fclose(fp);
    return 0;
}
