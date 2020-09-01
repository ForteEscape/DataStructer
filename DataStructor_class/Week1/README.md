# Week 1 - review C language

## Pointer
* 포인터 는 메모리 주소를 값으로 가지는 변수이다. 선언형식은 다음과 같다

<pre>
<code>
int * point_Int;
float * point_Float;
double * point_double;
</code>
</pre>

* 변수를 선언할 때와 같이 변수 타입을 적고 변수의 이름을 적기 이전 * 표시를 넣어 포인터 변수임을 명시한다.
* 포인터 변수에서 연산자 &(Ampersand) 는 그 변수의 주소를 추출하는 연산자이다.
* 포인터 변수에서 연산자 *(Asterisk) 는 그 포인터 변수가 가지고 있는 주소의 변수의 값을 추출하는 연산자이다.

<pre>
<code>
#include< stdio.h >

int main(){
    int number = 0;
    int * point_Int = &number;// 변수 number의 주소가 이 포인터 변수에 저장된다.
    int val = *pointer_Int    // val에는 point_Int가 가지고 있는 주소에 있는 변수 number의 값이 저장된다

    *point_Int = 10;          // 포인터 변수가 가리키는 주소에 있는 변수의 값을 10으로 변경한다.

    printf("%d\n", number);   // number는 10이 저장되어 출력될 것이다.
    
    return 0;
}

</code>
</pre>

## 포인터와 배열
* 다음과 같이 선언된 배열 arr_Int 가 있다고 가정하자

        int arr_Int[10];

* 이때 배열의 이름 arr_Int은 배열이 시작되는 주소를 저장하는 일종의 포인터 변수이다. 단, 그 값을 변경할 수 없다.
* 또한 이러한 배열에서 다음과 같은 연산이 성립한다. 이를 pointer arithmetic 라고 부른다.

        *arr_Int == arr_Int[0];
        *(arr_Int + 1) == arr_Int[1];
        *(arr_Int + i) == arr_Int[i];

## 동적 메모리 할당
* 변수를 선언하는 대신 프로그램의 요청으로 메모리를 할당할 수 있다. 이를 동적 메모리 할당이라고 한다.
* C언어에서는 malloc 함수를 호출하여 동적메모리 할당을 요청하면 요구하는 크기의 메모리를 할당하고 그 시작 주소를 반환한다.

* malloc 함수의 경우 다음과 같이 사용한다.

<pre>
<code>
#include< stdio.h >
#include< stdlib.h >

int main(){
    int * arr;
    arr = (int *)malloc(40);

    if(arr == NULL){
        // todo Null Exception
    }

    arr[0] = 12;
    arr[1] = 3;
    *(arr + 2) = 16;
}
</code>
</pre>

* malloc 함수가 반환하는 주소는 타입이 없는 주소(void * )이다. 따라서 정수를 저장하기 위해 이를 int * 로
캐스팅한다.
* malloc(byte_size)에서 byte_size는 할당할 메모리의 크기를 byte단위로 지정한다.