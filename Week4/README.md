# Week4 클래스, 객체, 참조변수

* Week4 에서는 Class, Method, Member(Field), Object 등의 개념을 학습합니다.

## Class
* 클래스는 하나의 type 이다 (int, double etc... 처럼)
* 단 Java가 정해놓은 타입이 아니라 사용자가 직접 정의하는 타입이므로 사용자 정의 타입이라고 부르기도 한다.
* 사용법은 다음과 같다

<pre>
<code>
public class Main{
    public static void main(String[] args){
        int number = 0;
        Person person;          // class 변수 person을 선언한다. 이때 아직 객체는 생성되지 않고 변수만 만들어지며 person의 값은 null 이다.
        person = new Person();  // new Person()에 의해 Person 객체가 만들어지고 person에 그 주소를 저장한다.

        person.name = "John";
        person.number = "01015147747"; // first가 가리키고 있는 Person 타입의 객체에 있는 name과 number 라는 이름의 필드에 각각 데이터를 저장한다.

        Person[] members = new Person[10]; // Person class의 배열 선언(as like array of pointer in C)

        for(int i = 0; i< 10; i++){
            members[i] = new Person(); // initialize Person array
        }
    }
}
</code>
</pre>

* premitive type과 class의 차이점
  premitive type의 변수의 경우 그 변수의 내부에 어떠한 값이 저장된다.
  class 의 경우 변수가 만들어지지만 그 변수의 내부에 데이터가 저장되지는 않는다.
  데이터를 저장할 객체는 new 키워드로 따로 만들어야 하고 class 변수에는 그 객체의 주소를 저장(참조)한다. (as like pointer in C)

* 모든 primitive type의 변수는 변수 자체에 값이 저장된다.
  primitive type이 아닌 모든 변수는 참조 변수이다.
  참조 변수는 실제 데이터를 저장하지 않으며 이를 저장할 객체는 new 명령으로 따로 만들어야 하고 참조 변수에는 그 객체의 주소를 저장한다.
