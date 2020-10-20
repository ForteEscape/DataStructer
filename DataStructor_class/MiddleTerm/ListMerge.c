#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* makeList(int arr[], int size);
Node* mergeList(Node* List1, Node* List2);
void print(Node* head);

int main()
{
	Node* List1_head = NULL;
	Node* List2_head = NULL;
	Node* List_merged = NULL;

	int number[10];
	int number2[10];

	for (int i = 0; i < 10; i++) {
		scanf("%d", &number[i]);
	}

	for (int i = 0; i < 10; i++) {
		scanf("%d", &number2[i]);
	}

	List1_head = makeList(number, 10, List1_head);
	List2_head = makeList(number2, 10, List2_head);

	//print(List1_head);
	//print(List2_head);

	mergeList(List1_head, List2_head);
}

Node* mergeList(Node* List1, Node* List2) {
	Node* head = NULL;
	Node* p = NULL;

	while (List1 != NULL && List2 != NULL) {
		if (List1->data <= List2->data) {
			if (head == NULL) {
				head = p = List1;
			}
			else {
				p->next = List1;
				p = List1;
			}
			List1 = List1->next;
		}
		else {
			if (head == NULL) {
				head = p = List2;
			}
			else {
				p->next = List2;
				p = List2;
			}
			List2 = List2->next;
		}
	}

	if (List1 != NULL) {
		p->next = List1;
	}
	if (List2 != NULL) {
		p->next = List2;
	}

	return head;
}

void print(Node* head) {
	Node* p = head;

	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

Node* makeList(int arr[], int size, Node* head) {
	for (int i = 0; i < size; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = arr[i];
		newNode->next = head;
		head = newNode;
	}

	return head;
}