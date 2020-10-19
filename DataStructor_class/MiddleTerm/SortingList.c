#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* head = NULL; // value of Linked List's address
void addFirst(int data);
void addMiddle(Node* prevNode, int data);
void addNode(int data);
void print();
void destruct();

int main()
{
	// our goal automatic sotrting when we input data in this linked list
	// if we input data such of 1 3 4 8 2 10 5 7 then linked list struct is 1 2 3 4 5 7 8 10
	int dataSet[10] = { 8, 3, 1, 5, 2, 4, 9, 7, 10, 6 };

	for (int i = 0; i < 10; i++) {
		addNode(dataSet[i]);
	}

	print();
	destruct();
}

void addNode(int data) {
	Node* p = head; // index of Linked List
	Node* q = NULL; // q is pointing previous node of p

	while (p != NULL && p->data < data) {
		q = p; // now q is pointing node which p pointing
		p = p->next; // p is move to next node
	}

	if (q == NULL) { // this mean the List is Empty(reason: p is pointing head and if head's node is null that mean list is empty)
		addFirst(data);
	}
	else {
		addMiddle(q, data);
	}
}

void addFirst(int data) { // add first node in linked list
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data; // Init struct member
	newNode->next = head; // newNode->next is head; head is NULL
	head = newNode; // now head is pointing newNode
}

void addMiddle(Node* prevNode, int data) { // head is not change in this function
	if (prevNode == NULL) { // if prevNode is Null this function is no longer needed
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node)); // make new Node
	newNode->data = data;
	newNode->next = prevNode->next; // now newNode's next is pointing prevNode's next => prevNode -> targetNode <- newNode
	prevNode->next = newNode; // now prevNode is pointing newNode => prevNode -> newNode -> targetNode
}

void print() {
	Node* p = head; // p is index of this Linked List

	while (p != NULL) { // travas this list
		printf("%d ", p->data);
		p = p->next;
	}
}

void destruct() {
	Node* p = head;

	while (p != NULL) {
		Node* temp = p;
		p = p->next;
		free(temp);
	}
}