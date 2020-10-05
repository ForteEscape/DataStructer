#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;
Node* head = NULL;

int main()
{
	head = (Node*)malloc(sizeof(Node));
	head->data = "data1";
	head->next = NULL;

	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "data2";
	q->next = NULL; // tail
	head->next = q; // link

	Node* p = head; // travas start in head
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}