#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable : 4996);

struct _RESULT{ // ans struct
    int ans_count = 0;
    char words[100];
};

char* eliminateSpecial(char* str);
void bubbleSort(char* string[], int size);
void swap(char* arr[], int front, int back);

int main()
{
    FILE* fp = fopen("pride_and_prejudice.txt", "r");
    char buffer[100];
    char* str[10000];
    char* target_arr[10000];
    int diff_flag = 1;
    int idx = 0;
    int res_idx = 0;
    int count = 0;

    struct _RESULT result[1000];

    while (fgets(buffer, 100, fp)) {
        if (strcmp(buffer, "\n") == 0) {
            continue;
        }

        for (int i = 0; i < 100; i++) { // minimalize
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = buffer[i] + 32;
            }
        }

        char* ptr = strtok(buffer, " ");

        while (ptr != NULL) {
            char* afterProcess = eliminateSpecial(ptr);

            if (strcmp(afterProcess, " ") == 0) {
                ptr = strtok(NULL, " ");
                continue;
            }
            str[idx] = strdup(afterProcess);
            idx++;

            ptr = strtok(NULL, " ");
        }
    }
    bubbleSort(str, idx);
    
    for (int i = 0; i < idx; i++) {
        if (strlen(str[i]) >= 7) {
            for (int j = 0; j < i; j++) {
                if (strcmp(str[i], str[j]) == 0) {
                    diff_flag = 0;
                    break;
                }
                diff_flag = 1;
            }
            if (diff_flag == 0) {
                continue;
            }

            strcpy(result[res_idx].words, str[i]);

            for (int j = i; j < idx; j++) {
                if (strcmp(str[i], str[j]) == 0) {
                    count++;
                }
            }
            result[res_idx].ans_count = count;
            res_idx++;
        }
        count = 0;
        diff_flag = 1;
    }

    for (int i = 0; i < res_idx; i += 10) {
        printf("%s %d\n", result[i].words, result[i].ans_count);
    }

    for (int i = 0; i < idx; i++) {
        free(str[i]);
    }

    fclose(fp);
}

char* eliminateSpecial(char* str) {
    char* afterStr = NULL;
    char tempBuf[10000];

    strcpy(tempBuf, str);

    for (int i = 0; i <= strlen(str); i++) { 
        if (tempBuf[i] >= 'a' && tempBuf[i] <= 'z') {   // 배열의 처음에서부터 진행하여 첫 알파벳을 만날 시 정지
            while (1) {                                 // tempBuf[0]이 공백이 아닐때까지 앞으로 끌어당기기
                if (tempBuf[0] != ' ') {
                    break;
                }
                else {
                    for (int j = 1; j <= strlen(str); j++) {
                        tempBuf[j - 1] = tempBuf[j];
                    }
                }
            }
            break;
        }
        else {
            tempBuf[i] = ' ';       // 유니코드 공백치환
        }
    }

    for (int i = strlen(str)-1; i >= 0; i--) {
        if (tempBuf[i] >= 'a' && tempBuf[i] <= 'z') { // 배열의 끝에서부터 진행하여 첫 알파벳을 만날 때 까지 널 문자로 치환
            break;
        }
        else {
            tempBuf[i] = '\0';
        }
    }

    afterStr = strdup(tempBuf);

    return afterStr;
}

void bubbleSort(char* string[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (strcmp(string[j], string[j + 1]) > 0) {
                swap(string, j, j+1);
            }
        }
    }
}

void swap(char* arr[], int front, int back) {
    char* temp = arr[front];
    arr[front] = arr[back];
    arr[back] = temp;
}