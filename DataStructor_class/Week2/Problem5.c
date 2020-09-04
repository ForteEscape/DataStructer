#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#pragma warning(disable : 4996);

int main()
{
    FILE* fp = fopen("pride_and_prejudice.txt", "r");
    char buffer[100];
    char* str[10000];
    int idx = 0;
    int diff_flag = 1;
    int temp;

    while (fgets(buffer, 100, fp)) {
        if (strcmp(buffer, "\n") == 0) {
            continue;
        }

        for (int i = 0; i < 100; i++) { // minimalize
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = buffer[i] + 32;
            }
        }
        //printf("%s", buffer); // log

        char* ptr = strtok(buffer, " ");

        while (ptr != NULL) {
            str[idx] = strdup(ptr);
            idx++;

            ptr = strtok(NULL, " ");
        }


        //scanf("%d", &temp); // break point

        //printf("%d\n", idx);
        /*for (int i = 0; i < idx; i++) {
            printf("str[%d] : %s\n", i, str[i]);
        }*/
    }

    for (int i = 0; i < idx; i++) {
        printf("%s\n", str[i]);
    }

    fclose(fp);
}