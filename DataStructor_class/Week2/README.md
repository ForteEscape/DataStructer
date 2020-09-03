# Week 2 - String

## 문자열 개요

* 문자열은 char 타입의 배열의 각 칸마다 문자 하나씩 저장된다.
* 문자열의 생성방법은 2가지로 나눌 수 있다.

<pre>
<code>
char str[10] = "hello";

char *str = "hello"; // 이렇게 정의된 경우 문자열 수정이 불가능하다.
</code>
</pre>


## String Library 함수
* 아래의 함수는 string.h를 include 해주어야 사용가능하다.

* strcpy : 문자열 복사
* strlen : 문자열 길이 반환
* strcat : 문자열 합치기
* strcmp : 문자열 비교