#include<stdio.h>
#include<string.h>
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
int add(int idx, char* data);
Node* remove_first();
Node* remove_Node(Node* prev);
Node* find(char* key);
Node* get_node(int idx);

int main()
{
	
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

int add(int idx, char* data) {
	if (idx < 0) {
		return 0;
	}
	
	/*Node* temp = (Node*)malloc(sizeof(Node)); 굳이 필요하진 않음 어차피 아래 함수에서 Node가 생성된다.
	temp->data = data;
	temp->next = NULL;*/

	if (idx == 0) {
		nodeInsert(data);
		return 1;
	}

	Node* prev = get_node(idx - 1);
	if (prev != NULL) {
		nodeInsert_after(prev, data);
		return 1;
	}

	return 0;
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

Node* find(char* key) {
	Node* p = head;
	while (p != NULL) {
		if (strcmp(p->data, key) == 0) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

Node* get_node(int idx) {
	if (idx < 0) {
		return NULL;
	}

	Node* p = head;
	for (int i = 0; i < idx && p != NULL; i++) {
		p = p->next;
	}

	return p;
}