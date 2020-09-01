#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void sorting(int size, int* data);
void swap(int* number1, int* number2);

// 원래 문제가 요구하는 의도대로 작성한 코드(동적메모리 구현)

int main() {
	int number;
	int elements;
	int* data;

	scanf("%d", &number);

	data = (int*)malloc(number * sizeof(int));

	if (data == NULL) {
		printf("malloc fail\n");
		return 0;
	}

	for (int i = 0; i < number; i++) {
		scanf("%d", &elements);
		*(data + i) = elements;
	}

	sorting(number, data);

	for (int i = 0; i < number; i++) {
		printf("%d\n", *(data + i));
	}
	free(data);

	return 0;
}

void sorting(int size, int* data) {
	if (size <= 0) {
		return;
	}
	else{
		for (int i = 0; i < size-1; i++) {
			if (*(data + i) > * (data + i + 1)) {
				swap((data + i), (data + i + 1));
			}
		}

		sorting(size - 1, data);
	}
}

void swap(int* number1, int* number2) {
	int temp = *number1;
	*number1 = *number2;
	*number2 = temp;
}