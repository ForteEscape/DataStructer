package Etc;

import java.util.Scanner;

public class Zero { // backjoon problem no.10773
    static int[] stack = new int[100001];
    static int size = 0;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int input_size = sc.nextInt();

        for(int i = 0; i<input_size; i++){
            int data = sc.nextInt();

            if(data == 0){
                pop();
            }
            else{
                push(data);
            }
        }

        sc.close();

        int sum = 0;
        for(int i = 0; i<size; i++){
            sum += stack[i];
        }
        System.out.println(sum);
    }

    static void pop(){
        //System.out.println("pop : " + stack[0]);
        for(int i = 1; i<=size; i++){
            stack[i-1] = stack[i];
        }
    }

    static void push(int data){
        if(stack[0] == 0){ // stack is empty
            stack[0] = data;
            size++;
        }
        else{
            if(size >= 1000000){
                System.out.println("stack is full");
                return;
            }
            else{
                for(int i = size; i>=0; i--){
                    stack[i+1] = stack[i];
                }
                stack[0] = data;
                size++;
            }
        }
    }
}