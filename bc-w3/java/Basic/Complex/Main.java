public class Main {
    public static void main(String[] args) throws CloneNotSupportedException {
        Complex a = new Complex(-1.1, 2.2);
        Complex b = new Complex(1.2, -2.1);
        Complex c = new Complex();
        
        System.out.println("a: " + a);
        System.out.println("b: " + b);
        System.out.println("c: " + c);
        
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
        
        c = a.multiply(b).clone();
        
        System.out.println("c: " + c);
    }
}
