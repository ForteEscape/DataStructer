#include "myQueue.h"

struct node {
	Item data;
	struct node* next;
	struct node* prev;
};

struct queue_head {
	struct node* head;
	struct node* tail;
};

Node* createNode_queue(Item i);
void chk_empty(queue q);

queue init() {
	queue newQueue = new queue_head;

	newQueue->head = NULL;
	newQueue->tail = NULL;

	return newQueue;
}

void push(queue q, Item i) {
	Node* newNode = createNode_queue(i);

	if (isEmpty(q)) { // if queue is empty
		q->head = newNode;
		q->tail = newNode;
	}
	else {
		newNode->prev = q->tail;
		q->tail->next = newNode;
		q->tail = newNode;
	}
}

Item pop(queue q) {
	chk_empty(q);

	Node* tempNode = q->head;
	Item element = tempNode->data;

	if (q->head == q->tail) { // pop unique node
		q->head = NULL;
		q->tail = NULL;
	}
	else {
		tempNode->next->prev = NULL;
		q->head = tempNode->next;
	}
	delete tempNode;

	return element;
}

Item front(queue q) {
	chk_empty(q);

	return q->head->data;
}

Item back(queue q) {
	chk_empty(q);

	return q->tail->data;
}

bool isEmpty(queue q) {
	return (q->head == NULL && q->tail == NULL);
}

Node* createNode_queue(Item i) {
	Node* newNode = new Node;

	newNode->data = i;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void chk_empty(queue q) {
	if (isEmpty(q)) {
		cout << "queue is empty" << endl;
		exit(EXIT_FAILURE);
	}
}