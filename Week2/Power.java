package Week2; // set of classes

import java.util.Scanner;

public class Power {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int number1 = sc.nextInt();
        int number2 = sc.nextInt();
        int result = 0;
        sc.close();

        result = power(number1, number2);

        System.out.println(result);
    }

    static int power(int num1, int num2){ // using funcion(method)
        int result = 1;

        for(int i = 0; i<num2; i++){
            result *= num1;
        }
        return result;
    }
}