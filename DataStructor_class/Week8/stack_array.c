#include "stack_array.h"
#define MAX_LEN 100

char stack[MAX_LEN];
int top = -1;

int is_full();
int is_empty();

void push(char ch) {
	if (is_full()) {
		printf("stack is full\n");
		return;
	}

	top++;
	stack[top] = ch;
}

char pop() {
	if (is_empty()) {
		return;
	}
	return stack[top--];
}

char peek() {
	return stack[top];
}

int is_empty() {
	return top == -1;
}

int is_full() {
	return top == MAX_LEN - 1;
}