package Week4;

public class Address {
    
    public static void main(String[] args){
        Person p1 = new Person(); // object

        p1.name = "John";
        p1.number = "1231445";

        System.out.println("Name : "+p1.name+", Number : "+p1.number);

        Person[] members = new Person[10]; // array of class

        members[1] = new Person();
        members[1].name = "David";
        members[1].number = "22124451";

        System.out.println("Name : "+members[1].name+", Number : "+members[1].number);
    }
}