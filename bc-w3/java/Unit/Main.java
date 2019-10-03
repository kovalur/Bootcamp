public class Main {
    public static void main(String[] args) {
        Unit barbarian = new Unit("Barbarian", 50, 20);
        Unit knight = new Unit("Knight", 45, 25);
        
        System.out.println(barbarian);
        System.out.println(knight);
        
        barbarian.attack(knight);
        knight.attack(barbarian);
        barbarian.attack(knight);
        
        System.out.println(barbarian);
        System.out.println(knight);
        
        knight.addHitPoints(46);
        barbarian.addHitPoints(51);
        knight.attack(barbarian);
        
        System.out.println(barbarian);
        System.out.println(knight);
    }
}
