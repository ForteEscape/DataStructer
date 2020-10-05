#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;
Node* head = NULL;

void nodeInsert(char* data);
int nodeInsert_after(Node* prev, char* data);
void nodeTravas(Node* head);

int main()
{
	char command[100];
	char data[100];

	while (1) {
		scanf("%s", command);
		if (strcmp(command, "middle") == 0) {
			//nodeInsert_after();
		}
		else {
			scanf("%s", data);
			nodeInsert(data);
		}
	}
}

int nodeInsert_after(Node* prev, char* data) {
	if (prev == NULL) {
		return 0;
	}

	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = prev->next;
	prev->next = temp;

	return 1;
}

void nodeInsert(char* data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = strdup(data);
	temp->next = head;
	head = temp;
}

void nodeTravas(Node* head) {
	Node* p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}