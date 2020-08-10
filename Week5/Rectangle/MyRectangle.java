package Week5.Rectangle;

public class MyRectangle{
    int width;
    int height;

    MyRectangle(int width, int height){
        this.width = width;
        this.height = height;
    }

    public int getArea(){
        int area;
        area = width * height;
        return area;
    }

    public int getWidth(){
        return width;
    }

    public int getHeight(){
        return height;
    }

    public void setWidth(int width){
        this.width = width;
    }

    public void setHeight(int height){
        this.height = height;
    }
}