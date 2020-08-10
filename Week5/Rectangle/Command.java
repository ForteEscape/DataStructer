package Week5.Rectangle;

import java.util.Scanner;

public class Command {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int width = sc.nextInt();
        int height = sc.nextInt();

        MyRectangle rectangle = new MyRectangle(width, height);

        int area = rectangle.getArea();

        System.out.println(area);
        sc.close();
    }
}