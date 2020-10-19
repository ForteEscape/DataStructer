#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct complex {
	int real_number;
	int image_number;
}Complex;

Complex complex_sum(Complex cpx_num1, Complex cpx_num2);
Complex makeComplex(char number[]);

int main()
{
	char numberBuffer1[100];
	char numberBuffer2[100];
	Complex cpx_num1;
	Complex cpx_num2;
	Complex cpx_sum;

	scanf("%s", numberBuffer1);
	cpx_num1 = makeComplex(numberBuffer1);
	scanf("%s", numberBuffer2);
	cpx_num2 = makeComplex(numberBuffer2);

	cpx_sum = complex_sum(cpx_num1, cpx_num2);

	if (cpx_sum.real_number == 0) {
		if (cpx_sum.image_number == 0) {
			printf("0\n");
		}
		else {
			printf("%di", cpx_sum.image_number);
		}
	}
	else if (cpx_sum.image_number == 0) {
		if (cpx_sum.real_number == 0) {
			printf("0\n");
		}
		else {
			printf("%d", cpx_sum.real_number);
		}
	}
}

Complex complex_sum(Complex cpx_num1, Complex cpx_num2) {
	Complex cpx_result;

	cpx_result.real_number = cpx_num1.real_number + cpx_num2.real_number;
	cpx_result.image_number = cpx_num1.image_number + cpx_num2.image_number;

	return cpx_result;
}

Complex makeComplex(char number[]) {
	int plusFlg = 0;
	int minusFlg = 0;

	for (int i = 0; i < number; i++) {
		if (number[i] == '+' && i != 0) {
			plusFlg = 1;
			break;
		}
		else if (number[i] == '-' && i != 0) { // make allow of -12+18i
			minusFlg = 1;
			break;
		}
	}

	Complex complex_num;
	complex_num.image_number = 0;
	complex_num.real_number = 0;

	char* ptr = NULL;

	if (plusFlg == 1) {
		ptr = strtok(number, "+");

		complex_num.real_number = atoi(ptr);

		ptr = strtok(NULL, "i");

		complex_num.image_number = atoi(ptr);
	}
	else if (minusFlg == 1) {
		ptr = strtok(number, "-");
		if (number[0] == '-') {
			complex_num.real_number = (atoi(ptr) - 2 * atoi(ptr));
		}
		else {
			complex_num.real_number = atoi(ptr);
		}

		ptr = strtok(NULL, "i");
		
		complex_num.image_number = (atoi(ptr) - 2 * atoi(ptr));
	}

	return complex_num;
}