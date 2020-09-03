#include<stdio.h>
#include<string.h>
#define size 100

int main()
{
    char* words[size] = {0, };
    char buffer[size];
    char tempBuf[size];
    int idx = 0;

    while(1){
        scanf("%s", buffer);

        if(strcmp(buffer, "EOF")){
            
        }
        strcpy(buffer, tempBuf);
        words[idx] = tempBuf;
        idx++;
    }

    for(int i = 0; i<idx; i++){
        printf("%s\n", words[i]);
    }
}