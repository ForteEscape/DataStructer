#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

/* 
						principle

	gcd(a1, a2, ..., an) = gcd(gcd(a1, a2, ..., a(n-1)), an)
	gcd(a1, a2, ..., a(n-1)) = gcd(gcd(a1, a2, ..., a(n-2)), a(n-1));
	...
	gcd(a1, a2, a3) = gcd(gcd(a1, a2), a3)
	gcd(a1, a2) = euqlid_alg(a1, a2)
*/


int euqlid_alg(int num1, int num2);

int main() {
	int number;
	int gcd = 0;
	int* data;

	scanf("%d", &number);

	data = (int*)malloc(sizeof(int) * number); // memory allocate

	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}

	for (int i = 0; i < number - 1; i++) {
		if (i == 0) {
			gcd = euqlid_alg(data[i], data[i + 1]);
		}
		else {
			gcd = euqlid_alg(gcd, data[i + 1]);
		}
	}

	printf("gcd of this data is %d\n", gcd);

	free(data);
}

int euqlid_alg(int num1, int num2) {
	while (num2 != 0) {
		int temp = num1;

		num1 = num2;
		num2 = temp % num1;
	}

	return num1;
}