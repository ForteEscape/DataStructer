package Week4;

public class Address {
    
    public static void main(String[] args){
        Person p1 = new Person(); // object

        p1.name = "John";
        p1.number = "1231445";

        System.out.println("Name : "+p1.name+", Number : "+p1.number);

        Person[] members = new Person[10]; // array of class, value of array element is null

        members[1] = new Person(); // 배열 내부로 바로 값을 넣을 수 없고 배열의 각 칸마다 Person 객체를 구현해주어야 한다.
        members[1].name = "David"; // 배열 각각의 칸은 Person객체의 주소를 가지게 된다.
        members[1].number = "22124451"; // Person 객체를 생성해 주지 않을 시 주소값이 null을 가리키므로 Null Point Exception이 발생한다.

        System.out.println("Name : "+members[1].name+", Number : "+members[1].number);
    }
}