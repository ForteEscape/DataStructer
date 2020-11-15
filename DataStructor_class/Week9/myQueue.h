#ifndef MYQUEUE_H
#define MYQUEUE_H
#include<iostream>
using namespace std;

typedef int Item;
typedef struct node Node;
typedef struct queue_head* queue;

queue init();
void push(queue q, Item i);
Item pop(queue q);
Item front(queue q);
Item back(queue q);
bool isEmpty(queue q);

#endif // !MYQUEUE_H

