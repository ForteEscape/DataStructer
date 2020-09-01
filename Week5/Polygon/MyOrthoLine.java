package Week5.Polygon;

public class MyOrthoLine {
    public MyPoint v; // node
    public MyPoint u;

    public MyOrthoLine(MyPoint p, MyPoint q){
        u = p;
        v = q;

        if(p.x > q.x || p.x == q.x && p.y > q.y){
            swap();
        }
    }

    private void swap(){
        MyPoint temp = u;
        u = v;
        v = temp;
    }

    public MyOrthoLine(int x1, int y1, int x2, int y2){
        v = new MyPoint(x1, y1);
        u = new MyPoint(x2, y2);
    }

    public boolean isVertical(){
        return (u.x == v.x);
    }

    public boolean isIntersect(MyOrthoLine other){
        if(isVertical() && !other.isVertical()){
            return (other.u.x < u.x && other.v.x > u.x && other.u.y > u.y && other.u.y < v.y);
        }
        else if(!isVertical() && other.isVertical()){
            return (other.u.y < u.y && other.v.y > u.y && other.u.x > u.x && other.u.x < v.x);
        }
        else{
            return false;
        }
    }
}