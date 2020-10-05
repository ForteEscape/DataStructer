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
Node* remove_first();
Node* remove_Node(Node* prev);
Node* find(char* key);

int main()
{
	// command;
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

Node* remove_first() { // Linked List의 첫 번째 노드를 삭제하고 그 노드의 주소를 반환한다.
	if (head == NULL) {
		return NULL;
	}
	else {
		Node* temp = head;
		head = head->next;

		return temp;
	}
}

Node* remove_Node(Node* prev) { // 어떠한 노드의 뒷 노드를 삭제하고 그 노드의 주소를 반환한다.
	Node* temp = prev->next;

	if (temp == NULL) {
		return NULL;
	}
	else {
		prev->next = temp->next;
		return temp;
	}
}

Node* find(char* key) { // 연결 리스트 순회
	Node* p = head;
	while (p != NULL) {
		if (strcmp(p->data, key) == 0) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}