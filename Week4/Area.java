package Week4;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Area {
    static AreaInfo[] areaInfo = new AreaInfo[1000];
    static int[] area = new int[1000];
    static int size = 0;

    public static void main(String[] args){
        Scanner inFile;
        try{
            String path = "C:\\Users\\sehunkim\\Desktop\\WorkSpace\\WorkSpace\\DataStructer\\Week4\\areaInput.txt";
            inFile = new Scanner(new File(path));

            while(inFile.hasNext()){
                int posx = inFile.nextInt();
                int posy = inFile.nextInt();
                int width = inFile.nextInt();
                int height = inFile.nextInt();

                areaInfo[size] = new AreaInfo(posx, posy, height, width);
                area[size] = areaInfo[size].getArea(height, width);
                size++;
            }
        }
        catch(FileNotFoundException e){
            System.out.println("No File");
        }

        bubbleSort();

        for(int i = 0; i<size; i++){
            areaInfo[i].printInfo();
        }
    }

    static void bubbleSort(){
        for(int i = size-1; i>0; i--){
            for(int j = 0; j<i; j++){
                if(area[j] > area[j+1]){
                    swap(j, j+1);
                }
            }
        }
    }

    static void swap(int num1, int num2){
        AreaInfo temp = areaInfo[num1];
        areaInfo[num1] = areaInfo[num2];
        areaInfo[num2] = temp;

        int area_temp = area[num1];
        area[num1] = area[num2];
        area[num2] = area_temp;
    }
}