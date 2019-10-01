public class Gun {
    private int amount;
    private int capacity;
    private boolean isReady;
    private String model;
    private int totalShots;
    
    public Gun(String model, int capacity) {
        this.model = model;
        this.capacity = capacity;
        this.amount = 0;
        this.isReady = false;
        this.totalShots = 0;
    }
    
    public Gun() {
        this("Beretta", 8);
    }
    
    public int getAmount() {
        return amount;
    }
    
    public int getCapacity() {
        return capacity;
    }
    
    public boolean isReady() {
        return isReady;
    }
    
    public String getModel() {
        return model;
    }
    
    public int getTotalShots() {
        return totalShots;
    }
    
    public void prepare() {
        if ( !isReady ) {
            isReady = !isReady;
        }
    }
    
    public void reload() {
        amount = capacity;
    }
    
    public void shoot() throws NotReady, OutOfRounds {
        if ( !isReady ) {
            throw new NotReady();
        }
        if ( amount == 0 ) {
            throw new OutOfRounds();
        }
        amount -= 1;
        totalShots += 1;
        System.out.println("Bang!");
    }
    
    public String toString() {
        StringBuffer out = new StringBuffer();
        
        out.append("Gun of model #" + model + "." + "\n");
        out.append(" details:" + "\n");
        out.append("  * magazine capacity: " + capacity + ";"+ "\n");
        out.append("  * bullets in magazine: " + amount + ";"+ "\n");
        out.append("  * is gun ready for usage: " + (isReady ? "Yes" : "No") + ";"+ "\n");
        out.append("  * number of shots fired: " + totalShots + "."+ "\n");
        
        return out.toString();
    }
}
