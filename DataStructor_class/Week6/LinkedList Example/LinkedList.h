#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
using namespace std;

typedef int Data;

typedef struct node {
	Data data;
	struct node* next;
}Node;

typedef struct linkedlist* LinkedList;

void add(LinkedList list, Data data); // 해당되는 linked list에 node 추가 node 삽입은 정렬되어 삽입되는 것으로 정의
void listTravas(LinkedList list); // node 순회
Node* removeNode(LinkedList list, Data key); // 해당되는 linked list에 key와 동일한 노드 삭제
Node* searchNode(LinkedList list, Data key); // 해당되는 linked list에 key와 동일한 노드 검색
LinkedList listCreate();

#endif // LINKEDLIST_H

