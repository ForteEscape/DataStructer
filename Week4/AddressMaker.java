package Week4;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class AddressMaker {
    static Person[] members = new Person[1000];
    static int count = 0;

    public static void main(String[] args){
        Scanner inFile;
        try{
            String path = "C:\\Users\\sehunkim\\Desktop\\WorkSpace\\WorkSpace\\DataStructer\\Week4\\input.txt";
            inFile = new Scanner(new File(path));

            while(inFile.hasNext()){
                String str1 = inFile.next();
                String str2 = inFile.next();

                members[count] = new Person();
                members[count].name = str1;
                members[count].number = str2;

                count++;
            }
            inFile.close();
        }
        catch(FileNotFoundException e){
            System.out.println("No File");
        }

        bubbleSort();

        for(int i = 0; i<count; i++){
            System.out.println("Name : "+members[i].name+" ,Number : "+members[i].number);
        }
    }

    static void bubbleSort(){
        for(int i = count-1; i >0; i-- ){
            for(int j = 0; j<i; j++){
                if(members[j].name.compareTo(members[j+1].name) > 0){
                    swap(j, j+1);
                }
            }
        }
    }

    static void swap(int num1, int num2){
        /*String temp_name;
        String temp_number;

        temp_name = members[num1].name;
        temp_number = members[num1].number;

        members[num1].name = members[num2].name;
        members[num1].number = members[num2].number;

        members[num2].name = temp_name;
        members[num2].number = temp_number;*/

        Person temp = new Person();

        temp = members[num1];
        members[num1] = members[num2]; //members 내부의 값들은 각 객체의 주소를 가지고 있으므로 이를 swap 하기만 해도 내부 값은 바뀔 것이다.
        members[num2] = temp;

        // 객체의 값이 바뀌는 것이 아니다 단지 객체를 가리키는 변수가 바뀌는 것이다.
    }
}