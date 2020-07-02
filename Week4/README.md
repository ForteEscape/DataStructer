# Week4 클래스, 객체, 참조변수

* Week4 에서는 Class, Object, reference Value 의 개념을 학습합니다.

## Class
* 클래스는 하나의 type 이다 (int, double etc... 처럼)
* 단 Java가 정해놓은 타입이 아니라 사용자가 직접 정의하는 타입이므로 사용자 정의 타입이라고 부르기도 한다.
* 어떠한 객체(우리가 원하는) 를 찍어내기 위한 일종의 설계도의 개념
* 사용법은 다음과 같다

<pre>
<code>
public class Main{
    public static void main(String[] args){
        int number = 0;
        Person person;  // class 변수 person을 선언한다. 이때 아직 객체는 생성되지 않고 변수만 만들어지며 person의 값은 null 이다.
        person = new Person();  // new Person()에 의해 Person 객체가 만들어지고 person에 그 주소를 저장한다.

        person.name = "John";
        person.number = "01015147747"; // first가 가리키고 있는 Person 타입의 객체에 필드에 각각 데이터를 저장한다.

        Person[] members = new Person[10]; // Person class의 배열 선언(as like array of pointer in C)

        for(int i = 0; i< 10; i++){
            members[i] = new Person(); // initialize Person array
        }
    }
}
</code>
</pre>

### premitive type과 class의 차이점
* premitive type의 변수의 경우 그 변수의 내부에 어떠한 값이 저장된다.
  class 의 경우 변수가 만들어지지만 그 변수의 내부에 데이터가 저장되지는 않는다.
  데이터를 저장할 객체는 ```new``` 키워드로 따로 만들어야 하고 class 변수에는 그 객체의 주소를 저장(참조)한다. (as like pointer in C)

* 모든 primitive type의 변수는 변수 자체에 값이 저장된다.
  primitive type이 아닌 모든 변수는 참조 변수이다.
  참조 변수는 실제 데이터를 저장하지 않으며 이를 저장할 객체는 new 명령으로 따로 만들어야 하고 참조 변수에는 그 객체의 주소를 저장한다.

* array의 경우에도 array 자체는 primitive type이 아니다. 따라서 array가 가지는 저장 공간 역시 new 명령으로 만들고 array의 이름
  즉 배열의 이름은 이 배열의 주소를 가지게 된다. (as like C pointer) 단 저장공간 내부는 primitive type이다.


## Call By Value, Call By Reference

* 일반적인 method parameter를 넘길 시 method에 있는 매개변수(parameter)는 호출시에 넘기는 매개변수를 복사하여
  함수의 매개변수에 넘겨주는 형식으로 돌아간다.

  <pre>
  <code>
  public class Example1{
    public static void main(String[] args){
      int number = 1;
      int number2 = 2;

      swap(number, number2);
    }

    static void swap(num1, num2){ // num1 에는 number의 값이 복사된다. num2에는 number2의 값이 복사된다.
      int temp;
      temp = num1;
      num1 = num2;
      num2 = temp;
    }
  }
  </code>
  </pre>
  
  위 코드에서 ```swap```은 ```number```, ```number2```의 값을 swap 해주지 않는다. 복사된 ```num1```, ```num2```의 값을 swap 해주는 것이기 때문이다.

* 다만 배열은 Call By Value에서 예외인 것처럼 보인다.
  <pre>
  <code>
  public class Example2{
      public static void main(String[] args){
          Scanner sc = new Scanner(System.in);
          int[] data = new int[10];

          for(int i = 0; i < 10; i++){
              data[i] = sc.nextInt();
          }

          bubbleSort(data, 10);
      }

      static void bubbleSort(int[] data, int size){
          // do bubble sort
      }
  }
  </code>
  </pre>
  
  위 코드에서 ```bubbleSort```의 결과로 정렬된 ```data```를 얻을 수 있다.
  이는 다음의 과정으로 설명이 가능하다.
  
1. ```bubbleSort()```를 호출하는 순간 배열의 변수 ```data```의 값이 호출된 ```bubbleSort()```의 매개변수 ```data```로 복사된다.

2. 그런데 복사된 값은 배열 ```data```의 주소이다 (이는 위에 설명된 것으로 인해 자명하다.) 따라서 호출하는 ```data```와 함수 매개변수 ```data```는
   동일한 배열을 가리키게 된다. (주소가 같으므로)

3. 따라서 함수 내부의 지역변수 ```data```의 값을 바꾸어도 동일 주소를 참조하는 main함수의 ```data```도 같이 값이 바뀌어진다.
