# Linked List

## List
- List의 기본적인 연산은 insert, remove, search등이 있다.

- list를 구현하는 대표적인 두 가지 방법은 array와 linked list가 있다.

- array로 구현하는 방식의 단점은 여러가지가 있다.
    1. 크기가 고정되어 크기를 넘어서는 데이터가 오면 reallocation이 필요하다.

    2. list의 중간에 원소를 삽입하거나 삭제할 경우에 다수의 데이터를 옮겨야 한다.

- linked list로 구현하는 방식의 특징은 다음과 같다.
    1. 다른 데이터의 이동이 필요하지 않고 중간에 insert 및 remove가 가능하다.

    2. 길이의 제한이 없다.

    3. 다만 랜덤 엑세스가 불가능하다. (즉 인덱스를 사용하여 값을 빼내오는것이 불가능하다.)

- 일반적으로 array를 사용한 데이터의 입력은 메모리 상에서는 연속된 공간에 데이터가 들어가는 구조로 되어 있다.

- 하지만 linked list에는 연속된 공간이 아닌 불규칙적인 공간에 데이터가 할당된다(메모리가 할당된다.)

## Linked List
- Linked List는 데이터에 다음 데이터의 주소를 가지는 추상적 자료구조이다.
    - ex) data = 1; next = 102;라면 다음 데이터는 102번지에 있다 라는 것이다.

- Linked List는 Node로 구성되어 있으며 각각의 Node는 필요한 데이터 필드와 하나 또는 그 이상의 링크 필드로 구성된다.

    - Link field는 다음 Node의 주소를 저장한다.

    - data field는 data를 저장한다.

    - 다만 Linked List 첫 번째 Node의 주소는 따로 저장해야 하며 잊어서는 안된다. 왜냐하면 첫 번째 Node의 주소를 어디에도 가지고 있지 않기 때문이다.

    - 마지막 Node의 Link field는 NULL을 가리켜 Linked List의 끝임을 표시한다.

- 일반적으로 Node는 다음과 같은 구조를 가진다

<pre>
<code>
struct Node{
    char* data; // can be other type
    struct Node* next; // Link field
}

typedef struct Node node;
node* head = NULL; // 연결 리스트의 첫 번째 노드의 주소를 저장할 포인터
</code>
</pre>

- ```struct Node* next```에서 자신과 동일한 구조체에 대한 포인터를 멤버로 가진다는 의미에서 자기참조형 구조체라고 부르기도 한다.

- 상세한 코드는 레포지토리의 코드 참조를 권장한다.