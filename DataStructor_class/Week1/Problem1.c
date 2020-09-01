#include<stdio.h>
#pragma warning(disable : 4996);

void sort_abc(int* a, int* b, int* c);
void swap(int* num1, int* num2);

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	sort_abc(&a, &b, &c);

	printf("%d %d %d\n", a, b, c);
}

void sort_abc(int* a, int* b, int* c) {
	while (1) {
		int flag = 0;

		if (*a > * b) {
			swap(a, b);
			flag = 1;
		}
		else {
			flag = 0;
		}

		if (*b > * c) {
			swap(b, c);
			flag = 1;
		}
		else {
			flag = 0;
		}

		if (flag == 0) break;
	}
}

void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp; 
}

