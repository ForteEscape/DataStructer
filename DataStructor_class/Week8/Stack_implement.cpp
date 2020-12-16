#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef int Data;

typedef struct node {
	Data data;
	struct node* next;
}Node;

typedef struct stack {
	struct node* head;
}Stack;

Stack* createStack();
void push(Stack* stack, Data data);
Data pop(Stack* stack);
Node* addNode(Data data);
Data peek(Stack* stack);
int isEmpty(Stack* stack);
int getStackIndex(int stackListIdx);

int main()
{
	int stackListIdx = 0;
	Stack* stackList[100] = { 0, };

	while (1) {
		int cmdListIdx = 0;
		char cmd[100] = { 0, };
		char* cmdList[2];
		
		printf("input command\n");
		printf("$ ");

		fgets(cmd, 1024, stdin);

		cmd[strlen(cmd) - 1] = '\0';

		while (getchar() != '\n');

		if (strcmp(cmd, "exit") == 0) {
			break;
		}

		char* ptr = strtok(cmd, " ");
		while (ptr != NULL) {
			cmdList[cmdListIdx] = strdup(ptr);
			cmdListIdx++;

			ptr = strtok(NULL, " ");
		}

		if (strcmp(cmdList[0], "Create") == 0) {
			stackList[stackListIdx] = createStack();

			printf("create stack success, stack number is %d\n", stackListIdx);
			stackListIdx++;
		}
		else if (strcmp(cmdList[0], "push") == 0) {
			int stackNumber = getStackIndex(stackListIdx);

			push(stackList[stackNumber], atoi(cmdList[1]));
		}
		else if (strcmp(cmdList[0], "pop") == 0) {
			int stackNumber = getStackIndex(stackListIdx);
			Data popData = pop(stackList[stackNumber]);

			if (popData != -1) {
				printf("pop success, data is %d\n", popData);
			}
		}
		else if (strcmp(cmdList[0], "peek") == 0) {
			int stackNumber = getStackIndex(stackListIdx);
			Data peekData = peek(stackList[stackNumber]);

			if (peekData != -1) {
				printf("peek success, data is %d\n", peekData);
			}
		}
	}
}

int getStackIndex(int stackListIdx) {
	int stackNumber;

	while (1) {
		printf("input stack number : ");
		scanf("%d", &stackNumber);

		if (stackNumber >= stackListIdx) {
			printf("invail stack number, try another stack number\n");
		}
		else {
			break;
		}
	}

	return stackNumber;
}

Stack* createStack() {
	Stack* newStack = (Stack*)malloc(sizeof(Stack));

	if (newStack == NULL) {
		printf("Error create stack fail\n");
		return NULL;
	}

	newStack->head = NULL;

	return newStack;
}

void push(Stack* stack, Data data) {
	Node* newNode = addNode(data);

	newNode->next = stack->head;
	stack->head = newNode;

	printf("push success\n");
}

Data pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Error - stack is empty\n");
		return -1;
	}
	Node* tempNode = stack->head;
	Data tempData = tempNode->data;

	stack->head = tempNode->next;

	free(tempNode);

	return tempData;
}

Data peek(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Error - stack is empty\n");
		return -1;
	}

	return stack->head->data;
}

Node* addNode(Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

int isEmpty(Stack* stack) {
	return (stack->head == NULL);
}