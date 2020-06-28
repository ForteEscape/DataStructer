package Week1_Basic;

import java.util.Scanner;

public class Max{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int number = sc.nextInt();
        int[] data = new int[number]; // variable length array

        for(int i = 0; i<number; i++){
            data[i] = sc.nextInt();
        }
        sc.close();

        int sum = 0;
        int max = data[0];

        for(int i = 0; i<number; i++){
            sum += data[i];
            if(data[i] > max){
                max = data[i];
            }
        }

        System.out.println("sum : "+sum);
        System.out.println("max : "+max);
    }
}