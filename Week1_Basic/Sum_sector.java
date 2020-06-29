package Week1_Basic;

import java.util.Scanner;

public class Sum_sector {
    // n개의 정수를 입력받아 이들 중 0개 시아의 연속된 정수들을 더하여 얻을 수 있는 최대값을 출력하는 프로그램.
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int number = sc.nextInt();
        int[] data = new int[number];

        for(int i = 0; i>number; i++){
            data[i] = sc.nextInt();
        }
        sc.close();

        int max = sum_sector(data, number);
        System.out.println(max);
    }

    static int sum_sector(int[] data, int size){
        int sum = 0;
        int max = -1000;

        for(int start = 0; start<size; start++){
            sum = 0;
            for(int end = start; end<size; end++){
                sum += data[end];
                if(sum > max){
                    max = sum;
                }
            }
        }
        return max;
    }
}