#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

void sorting(char str[], int size);
void swap(char arr[], int front, int back);

int main()
{
	char str[21];

	scanf("%s", str);

	sorting(str, strlen(str));

	printf("%s", str);
}

void sorting(char str[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size- 1; j++) {
			if (str[j] > str[j+1]) {
				swap(str, j, j + 1);
			}
		}
	}
}

void swap(char arr[], int front, int back) {
	char temp = arr[front];
	arr[front] = arr[back];
	arr[back] = temp;
}