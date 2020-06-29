package Week1_Basic;

import java.util.Scanner;

public class Overlap { // 사용자로부터 정수를 입력받아 중복된 정수 쌍의 개수를 카운트하여 출력한다.
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int size_arr = sc.nextInt();
        int[] data = new int[size_arr];

        for(int i = 0; i<size_arr; i++){
            data[i] = sc.nextInt();
        }
        sc.close();

        int result = countingOverlap(data, size_arr);

        System.out.println(result);
    }

    static int countingOverlap(int[] data, int size){
        int count = 0;

        for(int i = 0; i<size-1; i++){
            for(int j = i+1; i<size; i++){
                if(data[i] == data[j]) count++;
            }
        }

        return count;
    }
}