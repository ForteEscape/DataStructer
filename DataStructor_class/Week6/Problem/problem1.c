#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;
Node* head = NULL;

void listAdd(int idx, int value);
void addFirst(int data);
void addAfter(Node* prev, int data);

int listFind(int value);
void listCount(int value);

void removeFirst();
void removeAfter(Node* prev);
void listDelete(int value);
void list();

Node* getNode(int idx);

int main()
{
    char cmd[100];
    char* cmdList[3];

    while (1) {
        int idx = 0;

        printf("$ ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strlen(cmd) - 1] = '\0';

        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        char* ptr = strtok(cmd, " ");
        while (ptr != NULL) {
            cmdList[idx] = strdup(ptr);
            idx++;

            ptr = strtok(NULL, " ");
        }

        if (strcmp(cmdList[0], "add") == 0) {
            int idx = atoi(cmdList[1]);
            int value = atoi(cmdList[2]);

            listAdd(idx, value);
        }
        else if (strcmp(cmdList[0], "find") == 0) {
            int value = atoi(cmdList[1]);

            printf("%d\n", listFind(value));
        }
        else if (strcmp(cmdList[0], "count") == 0) {
            int value = atoi(cmdList[1]);
            
            listCount(value);
        }
        else if (strcmp(cmdList[0], "delete") == 0) {
            int value = atoi(cmdList[1]);

            listDelete(value);
        }
        else if (strcmp(cmdList[0], "list") == 0) {
            list();
        }
    }
    return 0;
}

void addFirst(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void addAfter(Node* prev, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = prev->next;
    prev->next = temp;
}

void listAdd(int idx, int value) {
    if (idx < 0) {
        printf("invalid index\n");
        return;
    }

    if (idx == 0) {
        addFirst(value);
        return;
    }

    Node* prev = getNode(idx - 1);
    
    if (prev == NULL) {
        printf("invalid index\n");
        return;
    }
    addAfter(prev, value);
}

int listFind(int value) {
    int idx = 0;
    Node* p = head;

    while (p != NULL) {
        if (value == p->data) {
            return idx;
        }
        idx++;
        p = p->next;
    }
    
    return -1;
}

void removeFirst() {
    if (head == NULL) {
        return;
    }
    else {
        Node* temp = head;
        head = head->next;

        free(temp);
    }
}

void removeAfter(Node* prev) {
    Node* temp = prev->next;

    if (temp == NULL) {
        return;
    }
    else {
        prev->next = temp->next;
        free(temp);
    }
}

void listDelete(int value) {
    int prev_idx = listFind(value);

    if (prev_idx < 0) {
        printf("not exist\n");
        return;
    }

    if (prev_idx == 0) {
        removeFirst();
    }

    Node* prev = getNode(prev_idx - 1);
    if (prev == NULL) {
        printf("not exist\n");
        return;
    }
    else {
        removeAfter(prev);
    }
}

void listCount(int value) {
    int count = 0;
    Node* p = head;

    while (p != NULL) {
        if (value == p->data) {
            count++;
        }
        p = p->next;
    }

    printf("%d\n", count);
}

void list() {
    Node* p = head;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

Node* getNode(int idx) {
    if (idx < 0) {
        return NULL;
    }

    Node* p = head;

    for (int i = 0; i < idx && p != NULL; i++) {
        p = p->next;
    }

    return p;
}