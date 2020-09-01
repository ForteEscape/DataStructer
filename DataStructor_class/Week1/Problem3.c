#include<stdio.h>
#pragma warning(disable:4996)
#define MAX 100

void sorting(int n, int* data);
void swap(int* num1, int* num2);

int main() {
	int number;
	int data[MAX];
	int elements;

	scanf("%d", &number);

	for (int i = 0; i < number; i++) {
		scanf("%d", &elements);
		*(data + i) = elements;
	}

	sorting(number, data);

	for (int i = 0; i < number; i++) {
		printf("%d\n", *(data + i));
	}
}

void sorting(int n, int* data) {
	if (n <= 0) return;
	else {
		for (int i = 0; i < n - 1; i++) {
			if (*(data + i) > * (data + i + 1)) {
				swap(data + i, data + i + 1);
			}
		}

		sorting(n - 1, data);
	}
}

void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}