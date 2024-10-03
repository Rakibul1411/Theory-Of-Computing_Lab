#include<stdio.h>
#include<stdbool.h>
#define Max_d 3


int mat[20][20][Max_d];
int indexOf(int nodes[],int ch){
    int size=sizeof(nodes)/sizeof(nodes[0]);
    for(int i=0;i<size;i++){
        if(nodes[i]==ch){
            return i;
        }
    }
}

int indeof(char signal[],char ch){
    int size=sizeof(signal)/sizeof(signal[0]);
    for(int i=0;i<size;i++){
        if(signal[i]==ch){
            return i;
        }
    }
}

bool NFA(int ind,char str[],int start,int num_f_state,int final[],char signal[],int n,int nodes[]){
    for(int i=0;i<num_f_state;i++){
        if((start == final[i])&&(str[ind]=='\0')){
            return true;
        }
        else if(str[ind]=='\0')
            return false;
    }
    int m = indexOf(nodes,start);

    int symbol = indeof(signal,str[ind]);
    for(int i=0;i<Max_d;i++){

        if(mat[m][symbol][i] != -1){
            if(NFA(ind+1,str,mat[m][symbol][i],num_f_state,final,signal,n,nodes)){
                return true;
            }
        }
    }
    return false;
}


int main(){
    int i,n,f,r,d;
    printf("Enter the number of states: ");
    scanf("%d",&n);
    int nodes[n];
    printf("Enter the states(name): ");
    for(i=0;i<n;i++){
        scanf("%d",&nodes[i]);
    }
    int inputNum;
    printf("Enter the number of input: ");
    scanf("%d",&inputNum);
    char signal[inputNum];
    printf("Enter all input signal : ");
    for(i=0;i<inputNum;i++){
        printf("\n");
        signal[i]=getchar();

    }


    //int mat[n][inputNum][Max_d];
    for(int i=0;i<n;i++){
        for(int j=0;j<inputNum;j++){
            for(int k=0;k<Max_d;k++){
                mat[i][j][k]=-1;
            }
        }
    }
    printf("\n\nTransitions:\n");
    for(int p=0;p<n;p++){
        for(int q=0;q<inputNum;q++){
            printf("\nWhile states %d and input symbol is %c :\nThe number of destination: ",nodes[p],signal[q]);
            scanf("%d",&d);
            if(d>0)
                printf("The transition states: ");
            for(int s=0;s<d;s++){
                scanf("%d",&mat[p][q][s]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<inputNum;j++){
            for(int k=0;k<Max_d;k++){
                printf("%d\t",mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    int start;
    printf("\nEnter start  states : ");
    scanf("%d",&start);
    printf("Enter the number of final states : ");
    int num_f_state;
    scanf("%d",&num_f_state);
    int final[num_f_state];

    printf("\nEnter  final states : ");
    for(int i=0;i<num_f_state;i++){
        scanf("%d",&final[i]);
    }
    int choice=1;

    while(choice){
        char str[100];
        printf("Enter the Input String: ");

        scanf("%s",str);
        bool result = NFA(0,str,start,num_f_state,final,signal,n,nodes);
        printf("\n");
        if(result)
            printf("\nAccepted\n");
        else
            printf("\nRejected\n");
        printf("Do you want to continue: ");
        scanf("%d",&choice);

    }

    return 0;
}
