#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAXLEN 100

typedef struct { /* 하나의 단어와 그 단어의 빈도수를 저장하기 위한 구조체 */
    char* word;
    int freq;
} Item;

struct node { /* 연결리스트의 노드의 구조를 정의하는 구조체 */
    Item* data;
    struct node* next;
};

typedef struct node Node;

Node* insert(Node*, char buf[]);

int main()
{
    char buf[MAXLEN];

    Node* head = NULL; /* head는 지역변수이다. */

    while (1) {
        scanf("%s", buf);
        if (strcmp(buf, "EOF") == 0) break; /* 문자열 “EOF”를 입력하면 종료 */
        head = insert(head, buf); /* 입력된 문자열을 연결리스트에 반영 */
    }

    Node* p = head;

    while (p != NULL) {
        printf("%s:%d\n", p->data->word, p->data->freq);
        p = p->next;
    }
    return 0;
}

Node* insert(Node* head, char buf[]) {
    /* 입력된 문자열을 연결리스트에 반영하고 head노드의 주소를 반환한다. 이미 존재하는.  */
    /* 문자열이면 카운트만 증가 하고, 아니라면 정렬된 순서로 연결리스트에 추가한다.  */

    Node* travas = head;
    Node* prev = NULL;
    
    while (travas != NULL) {
        if (strcmp(travas->data->word, buf) == 0) {
            travas->data->freq++;
            return head;
        }
        travas = travas->next;
    }

    travas = head;

    while (travas != NULL && (strcmp(travas->data->word, buf) <= 0)) {
        prev = travas;
        travas = travas->next;
    }
   
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = (Item*)malloc(sizeof(Item));

    if (prev == NULL) {
        temp->data->word = strdup(buf);
        temp->data->freq = 1;
        temp->next = head;

        return temp;
    }
    else {
        temp->data->word = strdup(buf);
        temp->data->freq = 1;
        temp->next = prev->next;

        prev->next = temp;
    }
    return head;
}