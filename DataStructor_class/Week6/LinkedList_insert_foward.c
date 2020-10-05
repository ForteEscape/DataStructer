#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;
Node* head = NULL;

void nodeInsert_head_global(char* data);
void nodeInsert_head_local(char* data, Node** head);
void nodeTravas(Node* head);
Node* nodeInsert(Node* head, char* data);

int main()
{
	Node* head_local = NULL;
	Node* head_local2 = NULL;

	for (int i = 0; i < 3; i++) {
		char data[100];
		scanf("%s", data);

		nodeInsert_head_global(data);
	}
	nodeTravas(head);
	printf("\n");

	for (int i = 0; i < 3; i++) {
		char data[100];
		scanf("%s", data);

		nodeInsert_head_local(data, &head_local);
	}
	nodeTravas(head_local);
	printf("\n");

	for (int i = 0; i < 3; i++) {
		char data[100];
		scanf("%s", data);

		head_local2 = nodeInsert(head_local2, data);
	}
	nodeTravas(head_local2);
}

Node* nodeInsert(Node* head, char* data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = strdup(data);
	tmp->next = head;
	
	return tmp;
}

void nodeInsert_head_global(char* data) { // using function like `nodeInsert_head_global(data);`
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = strdup(data);
	tmp->next = head;
	head = tmp;
}

void nodeInsert_head_local(char* data, Node** head) { //using function like `nodeInsert_head_local(data, &head);`
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = strdup(data);
	tmp->next = *head;
	*head = tmp;
}

void nodeTravas(Node* head) {
	Node* p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}