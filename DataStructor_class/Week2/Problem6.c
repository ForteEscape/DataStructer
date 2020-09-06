#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable : 4996);

int main()
{
	int row, colum;
	char buffer[20];
	char* string[101];
	int max[100] = { 0, };
	int idx = 1;

	scanf("%d %d", &row, &colum);

	for (int i = 1; i <= row * colum; i++) {
		scanf("%s", buffer);

		string[i] = strdup(buffer);
	}

	for (int i = 1; i <=colum; i++){
		for (int j = i; j <= row*colum; j+=colum) {
			if (max[i] < strlen(string[j])) {
				max[i] = strlen(string[j]);
			}
		}
	}

	for (int i = 1; i <= row * colum; i++) {
		if (colum == 1) {
			printf("%s\n", string[i]);
			continue;
		}
		if (i % colum == 1) {
			printf("%-*s", max[idx] + 1, string[i]);

			if (idx >= colum) {
				idx = 1;
			}
			else {
				idx++;
			}
		}
		else {
			if (i % colum == 0) {
				printf("%s\n", string[i]);
			}
			else {
				printf("%-*s", max[idx] + 1, string[i]);
			}

			if (idx >= colum) {
				idx = 1;
			}
			else {
				idx++;
			}
		}
	}

	for (int i = 1; i <= row * colum; i++) {
		free(string[i]);
	}
}