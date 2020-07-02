# Week5 Method, Constructor

* Week5에서는 Method, Constructor에 대한 개념과 그 예제들을 학습합니다.

## Method
* Class에서 서로 관련있는 data들 뿐 아니라 그 데이터와 관련이 있는 method도 함께 묶을 수 있다.
* Class에서 Method를 묶어놓으므로서 코드의 응집도를 높이고, 결합도를 낮출 수 있다.
* 응집도 => 관련성이 높은 요소들이 하나의 단위로 묶여 있는 경우 응집도가 높다라고 볼 수 있다.
* 결합도 => 다른 클래스에 의존하는 정도

<pre>
<code>
/* method를 사용하는 간단한 예제 */

public class Person{
    String name;
    String number;
    int age;

    public void printName(){ // class에서의 method
        System.out.println(name);
    }
}

public class Main{
    public static void main(String[] args){
        Person person = new Person(); // class Person을 가지고 만들어진 object를 가리키는 변수 person
        person.name = "David";

        person.printName(); // 여기서 실행하는 것은 class가 아니라 각각의 object 내부에 존재하는 메서드들이다.
    }
}
</code>
</pre>

* 핵심은 Week4에서 Class의 멤버로 멤버 변수(field)만을 가졌지만 method 역시 Class의 멤버로 포함시킬 수 있다는 것이다.

## 객체 (Object)
* OOP에서 객체란 'data + method' 이다. 
* data 부분은 객체의 정적 속성을 표현하며 method 부분은 객체의 기능(동적 속성)을 표현한다.
* 예로 자전거는 모양, 무게, 크기, 브렌드의 data(속성) 을 가지며 앞으로, 뒤로 움직인다 라는 기능을 가진다.

## Constructor
* Class 안에 Class와 동일한 이름을 가지며 return type이 없는 특별한 메서드를 둘 수 있다.
  이것을 생성자(Constructor) 라고 한다.
* Constructor는 new 명령으로 객체가 생성될 때 자동으로 실행된다. 주 목적은 객체의 field 값을 초기화시키는 것이다.

<pre>
<code>
/* construcor의 사용 예시 */

public class Person{
    String name;
    String number;
    int age;

    Person(String name, String number, int age){ // constructor
        this.name = name; // 
        this.number = number;
        this.age = age;
    }

    public int getAge(){
        return age;
    }
}

public class Main{
    public static void main(String[] args){
        Person person;

        String name = "David";
        String number = "01022411124";
        int age = 18;

        person = new Person(name, number, age);

        int someone_Age = person.getAge();

        System.out.println(someone_Age); // 18이 출력될 것이다.
    }
}
</code>
</pre>