public class Main {
    public static void main(String[] args) throws NotReady, OutOfRounds {
        Gun beretta = new Gun();
        Gun colt = new Gun("Colt", 2);
        
        System.out.println(beretta);
        System.out.println(colt);
        
        colt.reload();
        colt.prepare();
        
        colt.shoot();
        colt.shoot();
        
        System.out.println(beretta);
        System.out.println(colt);
        
        try {
            colt.shoot();
        } catch (OutOfRounds e) {
            System.out.println("No bullets left.");
        }
        
        try {
            beretta.shoot();
        } catch (NotReady e) {
            System.out.println("Gun is not prepared for shooting.");
        }
    }
}
