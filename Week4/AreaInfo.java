package Week4;

public class AreaInfo {
    public int squareX;
    public int squareY;
    public int height;
    public int width;

    AreaInfo(int squareX, int squareY, int height, int width){
        this.squareX = squareX;
        this.squareY = squareY;
        this.height = height;
        this.width = width;
    }

    public int getArea(int height, int width){
        int area = 0;

        area = height * width;

        return area;
    }

    public void printInfo(){
        System.out.println("pos x : "+squareX+", pos y : "+squareY+", width : "+width+", height : "+height+", area : "+getArea(height, width));
    }
}