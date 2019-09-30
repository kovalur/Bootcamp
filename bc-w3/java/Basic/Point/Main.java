public class Main {
    public static void main(String[] args) {
        Point x = new Point(2, 7);
        Point y = new Point(3, 8);
        Point z = new Point();
        
        System.out.println("x: " + x);
        System.out.println("y: " + y);
        System.out.println("z: " + z);
        
        if ( !x.equals(y) ) {
            System.out.println(x + " is not equal to " + y);
        } else {
            System.out.println(x + " is equal to " + y);
        }
        
        System.out.println("Distance: " + x.distance(y));
    }
}
