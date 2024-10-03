#include <stdio.h>
#include <string.h>
int main() {
    FILE *file = fopen("input.txt", "r");
    if(file == NULL){
        printf("Unable to open file");
        return 0;
    }
    char line[500];
    int totalComment=0, lineNumber=0;
    while (!feof(file)){
        fgets(line, 500, file);
        ++lineNumber;
        for (int i = 0; i < strlen(line); ++i) {
            if(line[i]=='/' && line[i+1]=='/'){
                ++totalComment;
                printf("\nLineNumber:%d\n", lineNumber);
                for (int j = i+2; line[j] !='\0' ; ++j) {
                    printf("%c", line[j]);
                }
            }
            else if(line[i]=='/' && line[i+1]=='*'){
                ++totalComment;
                int len = strlen(line);
                if(line[len-2] =='*' && line[len-1] =='/'){
                    printf("\nLineNumber:%d\n", lineNumber);
                    for (int j = i+2; line[j] !='*' && line[j+1] !='/'; ++j) {
                        printf("%c", line[j]);
                    }
                }
                else{
                    printf("\nLineNumber:%d\n", lineNumber);
                    for (int j = i+2; line[j] !='*' && line[j+1] !='/'; ++j) {
                            printf("%c", line[j]);
                        if(j== strlen(line)) {
                            //printf("\n\n");
                            fgets(line, 500, file);
                            ++lineNumber;

                            j=0;
                           // printf("LineNumber:%d\n", lineNumber);
                        }
                    }
                    printf("\n");
                }
            }
        }

    }
    printf("\nTotal number of comment is = %d", totalComment);
    return 0;
}
