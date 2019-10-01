public class Point implements Cloneable {
    private double x;
    private double y;
    
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    public Point() {
        this(0, 0);
    }
    
    public double getX() {
        return x;
    }
    
    public double getY() {
        return y;
    }
    
    public double distance(Point other) {
        return Math.hypot(other.x-this.x, this.y-other.y);
    }
    
    public boolean equals(Point other) {
        return other.x == this.x && other.y == this.y;
    }
    
    public String toString() {
        return "(" + this.x + ", " + this.y + ")";
    }
    
    public Point clone() throws CloneNotSupportedException {
        return (Point) super.clone();
    }
}
