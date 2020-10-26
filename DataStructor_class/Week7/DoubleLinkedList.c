#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}Node;

Node* head = NULL;
Node* tail = NULL;
int size = 0;

void addNodeAfter(Node* pre, int data);
void travas();
void travas_reverse();
Node* removeNode(Node* node);

int main()
{	
	addNodeAfter(NULL, 10);
	addNodeAfter(NULL, 12);
	addNodeAfter(NULL, 15);
	addNodeAfter(NULL, 7);
	addNodeAfter(NULL, 8);
	addNodeAfter(head->next, 11);

	printf("travas in right direction\n");
	travas(head);

	removeNode(tail->prev);

	travas(head);
}

void addNodeAfter(Node* pre, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (pre == NULL && head == NULL) { // empty list
		head = newNode;
		tail = newNode;
	}
	else if (pre == NULL) { // head is not NULL, add node in first place
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if (pre == tail) { // add node at the end
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	else { // add Node at the middle
		newNode->prev = pre;
		newNode->next = pre->next;
		pre->next->prev = newNode;
		pre->next = newNode;
	}
	size++;
}

Node* removeNode(Node* node) {
	Node* tempNode = (Node*)malloc(sizeof(Node));
	tempNode = node;

	if (head == node && tail == node) { // node is unique node in this list
		head = NULL;
		tail = NULL;
	}
	else if (head == node) { // if remove first node
		head = head->next;
		head->prev = NULL;
	}
	else if (tail == node) { // if remove last node
		tail = tail->prev;
		tail->next = NULL;
	}
	else { // if remove middle node in the list
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	size--;

	return tempNode;
}

void travas() {
	Node* first = head;

	while (first != NULL) {
		printf("%d ", first->data);
		first = first->next;
	}
	printf("\n");
}

void travas_reverse() {
	Node* end = tail;

	while (end != NULL) {
		printf("%d ", end->data);
		end = end->prev;
	}
	printf("\n");
}