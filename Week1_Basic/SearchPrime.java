package Week1_Basic;

import java.util.Scanner;

public class SearchPrime {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();

        sc.close();

        for(int i = 1; i<=number; i++){ // generalize
            if(isPrime(i)) System.out.println(i);
        }
    }

    static boolean isPrime(int number){
        for(int i = 2; i*i <= number; i++){
            if(number%i == 0){
                return false;
            }
        }
        return true;
    }
}