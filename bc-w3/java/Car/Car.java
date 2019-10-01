public class Car {
    private double fuelAmount;
    private double fuelCapacity;
    private double fuelConsumption;
    private Point location;
    private String model;
    
    public Car(double capacity, double consumption, Point location, String model) {
        this.fuelCapacity = capacity;
        this.fuelConsumption = consumption;
        this.location = location;
        this.model = model;
        this.fuelAmount = 0;
    }
    
    public Car() {
        this(60, 0.6, new Point(0, 0), "Mercedes");
    }
    
    public double getFuelAmount() {
        return fuelAmount;
    }
    
    public double getFuelCapacity() {
        return fuelCapacity;
    }
    
    public double getFuelConsumption() {
        return fuelConsumption;
    }
    
    public Point getLocation() {
        return location;
    }
    
    public String getModel() {
        return model;
    }
    
    public void drive(Point destination) throws OutOfFuel, ToMuchFuel {
        double fuelNeeded = this.location.distance(destination) * this.fuelConsumption;
        
        if ( fuelNeeded > this.fuelCapacity ) {
            throw new OutOfFuel();
        }
        
        if ( fuelNeeded > this.fuelAmount ) {
            this.refill(fuelNeeded-this.fuelAmount);
        }
        this.location = destination;
        this.fuelAmount -= fuelNeeded;
    }
    
    public void drive(double x, double y) throws OutOfFuel, ToMuchFuel {
        double fuelNeeded = this.location.distance(new Point(x, y)) * this.fuelConsumption;
        
        if ( fuelNeeded > this.fuelCapacity ) {
            throw new OutOfFuel();
        }
        
        if ( fuelNeeded > this.fuelAmount ) {
            this.refill(fuelNeeded-this.fuelAmount);
        }
        this.location = new Point(x, y);
        this.fuelAmount -= fuelNeeded;
    }
    
    public void refill(double fuel) throws ToMuchFuel {
        double fuelAfterRefill = this.fuelAmount + fuel;
        
        if ( fuelAfterRefill > this.fuelCapacity ) {
            throw new ToMuchFuel();
        }
        this.fuelAmount = fuelAfterRefill;
    }
    
    public String toString() {
        StringBuffer out = new StringBuffer();
        
        out.append("Car of model #" + this.model + " is located at " + this.location + "." + "\n");
        out.append(" details:" + "\n");
        out.append("  * fuel capacity, l: " + this.fuelCapacity + ";" + "\n");
        out.append("  * fuel ammount, l: " + this.fuelAmount + ";" + "\n");
        out.append("  * fuel consumption, l/km: " + this.fuelConsumption + "." + "\n");
        
        return out.toString();
    }
}
