package Etc;

import java.util.Scanner;

public class MyStack {
    static int[] stack_arr = new int[10000];
    static int size = 0;
    public static void main(String[] args){
        process();
    }

    static void process(){
        Scanner sc = new Scanner(System.in);
        Scanner cmd = new Scanner(System.in);
        int command_num = sc.nextInt();

        for(int i = 0; i<command_num; i++){
            String command = cmd.nextLine();

            if(command.equals("push")){
                int number = sc.nextInt();
                number_push(number);
            }
            else if(command.equals("pop")){
                number_pop();
            }
            else if(command.equals("size")){
                System.out.println(getSize());
            }
            else if(command.equals("empty")){
                System.out.println(isEmpty());
            }
            else if(command.equals("top")){
                getTop();
            }
        }
        sc.close();
        cmd.close();
    }

    static void number_push(int number){ // LIFO
        if(isEmpty() == 1){
            stack_arr[0] = number;
        }
        else{
            if(getSize() >= 10000){
                System.out.println("stack is full");
                return;
            }

            for(int i = getSize(); i>=0; i--){
                stack_arr[i+1] = stack_arr[i];
            }
            stack_arr[0] = number;
        }
    }

    static void number_pop(){
        if(isEmpty() == 1){
            System.out.println("-1");
            return;
        }

        int pop_num = stack_arr[0];

        for(int i = 1; i<=getSize(); i++){
            stack_arr[i-1] = stack_arr[i];
        }
        size--;

        System.out.println(pop_num);
    }

    static int isEmpty(){
        for(int i = 0; i<10000; i++){
            if(stack_arr[i] != 0){
                return 0;
            }
        }
        return 1;
    }

    static int getSize(){
        int size = 0;

        for(int i = 0; i<10000; i++){
            if(stack_arr[i] != 0){
                size++;
            }
        }

        return size;
    }

    static void getTop(){
        if(isEmpty() == 1){
            System.out.println("-1");
            return;
        }
        System.out.println(stack_arr[0]);
    }
}