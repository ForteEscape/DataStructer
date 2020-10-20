#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

// stack implement with single direction linked list

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* top = NULL;
Node* push(int data);
Node* pop();
Node* getTop();
int size();
int empty();

int main()
{
	Node* N;
	int number;
	int data;
	char buffer[100];

	scanf("%d", &number);
	getchar();

	for (int i = 0; i < number; i++) {
		fgets(buffer, 100, stdin);
		buffer[strlen(buffer) - 1] = '\0';

		if (strcmp(buffer, "pop") == 0) {
			N = pop();
			if (N == NULL) {
				printf("-1\n");
			}
			else {
				printf("%d\n", N->data);
			}
			free(N);
		}
		else if (strcmp(buffer, "top") == 0) {
			N = getTop();
			if (N == NULL) {
				printf("-1\n");
			}
			else {
				printf("%d\n", N->data);
			}
		}
		else if (strcmp(buffer, "size") == 0) {
			printf("%d\n", size());
		}
		else if (strcmp(buffer, "empty") == 0) {
			printf("%d\n", empty());
		}
		else {
			char* ptr = strtok(buffer, " ");
			if (strcmp(ptr, "push") == 0) {
				ptr = strtok(NULL, " ");
				top = push(atoi(ptr));
			}
		}
	}
}

Node* push(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = top;

	return newNode;
}

Node* pop() {
	if (top == NULL) {
		return NULL;
	}

	Node* tmpNode = top;
	top = top->next;

	return tmpNode;
}

Node* getTop() {
	return top;
}

int size() {
	int count = 0;
	Node* p = top;

	while (p != NULL) {
		count++;
		p = p->next;
	}

	return count;
}

int empty() {
	if (top == NULL) {
		return 1;
	}
	
	return 0;
}