package Week5.Polygon;

public class OrthoPolygon {
    public int num;
    public MyPoint[] vertices;

    public OrthoPolygon(int k){
        num = 0;
        vertices = new MyPoint[k];
    }

    public void addVertax(int x, int y){
        vertices[num++] = new MyPoint(x, y);
    }

    public int maxX(){
        int max = vertices[0].x;

        for(int i = 0; i<num; i++){
            if(vertices[i].x > max){
                max = vertices[i].x;
            }
        }

        return max;
    }

    public boolean isContain(MyPoint p){
        MyOrthoLine arrow = new MyOrthoLine(p, new MyPoint(maxX()+1, p.y));
        int count = 0;

        for(int i = 0; i<num; i++){
            MyOrthoLine edge = new MyOrthoLine(vertices[i], vertices[i+1]);
            if(arrow.isIntersect(edge)){
                count++;
            }
        }
        
        if(count % 2 == 0){
            return true;
        }
        else{
            return false;
        }
    }
}