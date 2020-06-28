package Week1_Basic;

import java.util.Scanner;

public class Shift {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int number = sc.nextInt();
        int[] data = new int[number];

        for(int i = 0; i<number; i++){
            data[i] = sc.nextInt();
        }
        sc.close();

        print(data, number);
        shift(data, number);
        System.out.println("");
        print(data, number);
    }

    static void shift(int[] data, int number){
        int temp = data[number-1];

        for(int i = number-2; i>=0; i--){
            data[i+1] = data[i];
        }
        data[0] = temp;
    }

    static void print(int[]data, int number){
        for(int i = 0; i<number; i++){
            System.out.println(data[i]);
        }
    }
}