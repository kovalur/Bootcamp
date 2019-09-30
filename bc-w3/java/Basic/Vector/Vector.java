public class Vector implements Cloneable {
    private double x;
    private double y;
    
    public Vector(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    public Vector() {
        this(0, 0);
    }
    
    public double getX() {
        return x;
    }
    
    public double getY() {
        return y;
    }
    
    public void setX(double x) {
        this.x = x;
    }
    
    public void setY(double y) {
        this.y = y;
    }
    
    public double len() {
        return Math.hypot(x, y);
    }
    
    public boolean equals(Vector other) {
        return this.x == other.x && this.y == other.y;
    }
    
    public void incrementedBy(Vector other) {
        this.x += other.x;
        this.y += other.y;
    }
    
    public void decrementedBy(Vector other) {
        this.x -= other.x;
        this.y -= other.y;
    }
    
    public Vector plus(Vector other) {
        Vector sumOfVectors = new Vector();
        
        sumOfVectors.x = this.x + other.x;
        sumOfVectors.y = this.y + other.y;
        
        return sumOfVectors;
    }
    
    public Vector minus(Vector other) {
        Vector diffOfVectors = new Vector();
        
        diffOfVectors.x = this.x - other.x;
        diffOfVectors.y = this.y - other.y;
        
        return diffOfVectors;
    }
    
    public String toString() {
        StringBuffer out = new StringBuffer();
        
        out.append("(" + String.format("%.0f", this.x) + ", " + String.format("%.0f", this.y) + ")");
        
        return out.toString();
    }
    
    public Vector clone() throws CloneNotSupportedException {
        return (Vector) super.clone();
    }
}
