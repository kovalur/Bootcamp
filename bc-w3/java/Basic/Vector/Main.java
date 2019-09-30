public class Main {
    public static void main(String[] args) throws CloneNotSupportedException {
        Vector a = new Vector(1, 5);
        Vector b = new Vector(5, 1);
        Vector c = new Vector();
        
        System.out.println("a: " + a);
        System.out.println("b: " + b);
        System.out.println("c: " + c);
        
        System.out.println("Length of a: " + a.len());
        
        c = a.clone();
        a.incrementedBy(b);
        
        if ( !a.equals(b) ) {
            System.out.println(a + " is not equal to " + b);
        } else {
            System.out.println(a + " is equal to " + b);
        }
        
        b.incrementedBy(c);
        
        a.decrementedBy(c);
        b.decrementedBy(a);
        c = a.plus(b).clone();
        
        System.out.println("a: " + a);
        System.out.println("b: " + b);
        System.out.println("c: " + c);
        
        c = a.minus(b).clone();
        
        System.out.println("c: " + c);
    }
}


