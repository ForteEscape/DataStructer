#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#pragma warning(disable : 4996);
#define SIZE 100
#define WORD_SIZE 21

char* strlwr(char* str);

int main()
{
    char* words[SIZE] = { 0, };
    char buffer[WORD_SIZE];
    int idx = 0;
    int count = 0;
    int diff_flag = 1;

    while (1) {
        scanf("%s", buffer);

        if (strcmp(buffer, "EOF") == 0) {
            printf("%d\n", count);
            break;
        }

        words[idx] = strdup(strlwr(buffer));

        for (int i = 0; i < idx; i++) {
            if (strcmp(words[i], strlwr(buffer)) == 0) {
                diff_flag = 0;
                break;
            }
            diff_flag = 1;
        }

        if (diff_flag == 1) {
            count++;
        }

        idx++;
    }

    for (int i = 0; i < idx; i++) {
        free(words[i]);
    }
}

char* strlwr(char* str) {
    unsigned char* p = (unsigned char*)str;

    while (*p) {
        *p = tolower((unsigned char)*p);
        p++;
    }

    return str;
}