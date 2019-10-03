public class Unit {
    private int damage;
    private int hitPoints;
    private int hitPointsLimit;
    private String name;
    
    public Unit(String name, int hp, int dmg) {
        this.name = name;
        this.hitPoints = hp;
        this.hitPointsLimit = hp;
        this.damage = dmg;
    }
    
    private void ensureIsAlive() throws UnitIsDead {
        if ( hitPoints == 0 ) {
            throw new UnitIsDead();
        }
    }
    
    public int getDamage() {
        return damage;
    }
    
    public int getHitPoints() {
        return hitPoints;
    }
    
    public int hitPointsLimit() {
        return hitPointsLimit;
    }
    
    public String getName() {
        return name;
    }
    
    public void addHitPoints(int hp) {
        int newHp = this.hitPoints + hp;
        
        if ( hp <= 0 ) {
            return;
        }
        
        try {
            this.ensureIsAlive();
        } catch (UnitIsDead e) {
            return;
        }
        
        if ( newHp > this.hitPointsLimit ) {
            this.hitPoints = this.hitPointsLimit;
            return;
        }
        this.hitPoints = newHp;
    }
    
    public void takeDamage(int dmg) {
        int newHp = this.hitPoints - dmg;
        
        try {
            this.ensureIsAlive();
        } catch (UnitIsDead e) {
            return;
        }
        
        if ( newHp > 0 ) {
            this.hitPoints = newHp;
            return;
        }
        this.hitPoints = 0;
    }
    
    public void attack(Unit enemy) {
        try {
            this.ensureIsAlive();
        } catch (UnitIsDead e) {
            return;
        }
        
        enemy.takeDamage(this.damage);
        if ( enemy.hitPoints > 0 ) {
            this.counterAttack(enemy);
        }
    }
    
    public void counterAttack(Unit enemy) {
        int newHp = this.hitPoints - enemy.damage / 2;
        
        if ( newHp > 0 ) {
            this.hitPoints = newHp;
            return;
        }
        this.hitPoints = 0;
    }
    
    public String toString() {
        StringBuffer out = new StringBuffer();
        
        out.append("Unit name is: " + this.name + "." + "\n");
        out.append(" details: " + "\n");
        out.append("  * damage: " + this.damage + ";" + "\n");
        out.append("  * hit points: " + this.hitPoints + ";" + "\n");
        out.append("  * hit points limit: " + this.hitPointsLimit + "." + "\n");
        return out.toString();
    }
}
