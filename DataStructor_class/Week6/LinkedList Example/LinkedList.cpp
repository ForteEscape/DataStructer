#include "LinkedList.h"

struct linkedlist {
	struct node* head;
};

Node* createNode(Data data);
Node* searchNode_r(LinkedList list, Data key);
bool isListEmpty(LinkedList list);

LinkedList listCreate() {
	LinkedList newList = new linkedlist;
	newList->head = NULL;

	return newList;
}

void add(LinkedList list, Data data) {
	Node* newNode = createNode(data);

	if (isListEmpty(list)) { // empty list
		list->head = newNode;
		return;
	}

	Node* index = list->head;
	Node* follow = NULL;

	while (index != NULL && index->data > data) {
		follow = index;
		index = index->next;
	}

	if (follow == NULL) { // add first
		newNode->next = list->head;
		list->head = newNode;
	}
	else { // add middle
		newNode->next = follow->next;
		follow->next = newNode;
	}
}

void listTravas(LinkedList list) {
	Node* index = list->head;

	while (index != NULL) {
		cout << "data : " << index->data << endl;
		index = index->next;
	}
}

Node* searchNode(LinkedList list, Data key) {
	if (isListEmpty(list)) {
		cout << "this list is empty" << endl;
		return NULL;
	}
	Node* index = list->head;

	while (index != NULL && index->data != key) {
		index = index->next;
	}

	return index;
}

Node* removeNode(LinkedList list, Data key) {
	if (isListEmpty(list)) {
		cout << "this list is empty" << endl;
		return NULL;
	}

	Node* tempNode = searchNode(list, key);
	Node* targetfollow = searchNode_r(list, key);

	if (tempNode == NULL) {
		cout << "No such value" << endl;
		return NULL;
	}

	if (targetfollow == NULL) {
		list = NULL;
	}
	else {
		targetfollow->next = tempNode->next;
	}

	return tempNode;
}

Node* searchNode_r(LinkedList list, Data key) {
	if (isListEmpty(list)) {
		cout << "this list is empty" << endl;
		return NULL;
	}
	Node* index = list->head;
	Node* follow = NULL;

	while (index != NULL && index->data != key) {
		follow = index;
		index = index->next;
	}

	return follow;
}

Node* createNode(Data data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

bool isListEmpty(LinkedList list) {
	return list->head == NULL;
}