public class Main {
    public static void main(String[] args) throws ToMuchFuelException, OutOfFuelException, CloneNotSupportedException {
        Car car = new Car();
        
        System.out.println(car);
        
        System.out.println("Your max travel distance: " + (new Point(0, 0).distance(new Point(50, 86.6025403784)) * car.getFuelConsumption()) + "km.");
        
        try {
            car.drive(50, 86.6025403785);
        } catch (OutOfFuelException e) {
            System.out.println("Size of fuel tank is too small for your journey.");
        }
        
        try {
            car.refill(61);
        } catch (ToMuchFuelException e) {
            System.out.println("You can't fuel more of tank capacity.");
        }
        
        car.drive(new Point(5, 11));
        
        System.out.println(car);
    }
}
