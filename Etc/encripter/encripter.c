#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

char alphabetArr[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

char* encript_add(int key, char text[]);
char* encript_mul(int key, char text[]);

int main()
{
	while (1) {
		int idx = 0;
		int key;
		char cmdBuffer[10000];
		char* cmdArr[4];

		printf("$ ");

		fgets(cmdBuffer, sizeof(cmdBuffer), stdin);
		cmdBuffer[strlen(cmdBuffer) - 1] = '\0';

		char* ptr = strtok(cmdBuffer, " ");
		while (ptr != NULL) {
			cmdArr[idx] = strdup(ptr);

			idx++;
			ptr = strtok(NULL, " ");
		}

		if (strcmp(cmdArr[0], "add") == 0) {
			key = atoi(cmdArr[1]);
			printf("%s\n",encript_add(key, cmdArr[2]));
		}
		else if (strcmp(cmdArr[0], "mul") == 0) {
			key = atoi(cmdArr[1]);
			printf("%s\n", encript_mul(key, cmdArr[2]));
		}
		else if (strcmp(cmdArr[0], "arfin") == 0) {

		}
	}
}

char* encript_add(int key, char text[]) {
	int len = strlen(text);
	int* textCode = (int*)malloc(sizeof(int) * len);

	char encript_txt[10000];

	if (textCode == NULL || len <= 0) {
		return NULL;
	}
	else {
		for (int i = 0; i < len; i++) { // transform text to code
			for (int j = 0; j < 26; j++) {
				if (text[i] == alphabetArr[j]) {
					textCode[i] = j;
				}
			}
		}

		for (int i = 0; i < len; i++) { // encript operation
			textCode[i] = (textCode[i] + key) % 26; // mod 26
		}

		for (int i = 0; i < len; i++) {
			encript_txt[i] = alphabetArr[textCode[i]];
		}
		encript_txt[len] = '\0';
		
		char* encript_str = encript_txt;

		free(textCode);
		return encript_str;
	}
}

char* encript_mul(int key, char text[]) {
	int len = strlen(text);
	int* textCode = (int*)malloc(sizeof(int) * len);

	char encript_txt[10000];

	if (textCode == NULL || len <= 0) {
		return NULL;
	}
	else {
		for (int i = 0; i < len; i++) { // transform text to code
			for (int j = 0; j < 26; j++) {
				if (text[i] == alphabetArr[j]) {
					textCode[i] = j;
				}
			}
		}

		for (int i = 0; i < len; i++) { // encript operation
			textCode[i] = (textCode[i] * key) % 26; // mod 26
		}

		for (int i = 0; i < len; i++) {
			encript_txt[i] = alphabetArr[textCode[i]];
		}
		encript_txt[len] = '\0';

		char* encript_str = encript_txt;

		free(textCode);
		return encript_str;
	}
}