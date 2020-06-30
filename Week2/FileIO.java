package Week2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FileIO {
    // input data with input file (.txt, etc...)
    public static void main(String[] args) {
        Scanner inFile;
        try { // input with file, we need to handle Exception
            String path = "C:\\Users\\sehunkim\\Desktop\\WorkSpace\\WorkSpace\\DataStructer\\Week2\\input.txt";
            inFile = new Scanner(new File(path));

            String[] name = new String[1000];
            String[] number = new String[1000];
            int count = 0;

            while(inFile.hasNext()){ // detect EOF
                name[count] = inFile.next();
                number[count] = inFile.next();
                count++;
            }
            inFile.close();

            bubbleSorting(name, number, count);

            for(int i = 0; i<count; i++){
                System.out.println("name : "+name[i]+", number : "+number[i]);
            }
        } 
        catch (FileNotFoundException e) { // Exception throw when file is not exsist
            System.out.println("No file");
            System.exit(9);
        }
    }

    static void bubbleSorting(String[] name, String[] number, int size){
        for(int i = size-1; i>0; i--){
            for(int j = 0; j<i; j++){
                /*if(Integer.parseInt(number[j]) > Integer.parseInt(number[j+1])){ // sorting with number
                    swap(j, j+1, name, number);
                }*/
                if(name[j].compareTo(name[j+1]) > 0){ // sorting with name
                    swap(j, j+1, name, number);
                }
            }
        }
    }

    static void swap(int a, int b, String[] name, String[] number){
        String temp_num;
        String temp_name;

        temp_name = name[a];
        temp_num = number[a];

        name[a] = name[b];
        number[a] = number[b];

        name[b] = temp_name;
        number[b] = temp_num;
    }
}