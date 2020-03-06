<?php
    class UnitIsDead extends Exception {}
    
    class Unit {
        private $damage;
        private $hitPoints;
        private $hitPointsLimit;
        private $name;
        
        private function validate($value) {
            if ( is_int($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        private function ensureIsAlive() {
            if ( $this->hitPoints == 0 ) {
                throw new UnitIsDead("State error: unit is dead");
            }
        }
        
        public function __construct($name, $hp, $dmg) {
            $this->name = $name;
            $this->hitPoints = $this->validate($hp);
            $this->hitPointsLimit = $hp;
            $this->damage = $this->validate($dmg);
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function __set($name, $value) {
            throw new Exception("Action error: attribute change not allowed");
        }
        
        public function addHitPoints($hp) {
            $newHp = $this->hitPoints + $this->validate($hp);
            
            if ( $hp <= 0 ) {
                return;
            }
            
            $this->ensureIsAlive();
            
            if ( $newHp > $this->hitPointsLimit ) {
                $this->hitPoints = $this->hitPointsLimit;
                return;
            }
            $this->hitPoints = $newHp;
        }
        
        public function takeDamage($dmg) {
            $newHp = $this->hitPoints - $this->validate($dmg);
            
            if ( $dmg <= 0 ) {
                return;
            }
            
            $this->ensureIsAlive();
            
            if ( $newHp > 0 ) {
                $this->hitPoints = $newHp;
                return;
            }
            $this->hitPoints = 0;
        }
        
        public function attack(Unit $enemy) {
            $this->ensureIsAlive();
            
            $enemy->takeDamage($this->damage);
            if ( $enemy->hitPoints > 0 ) {
                $this->counterAttack($enemy);
            }
        }
        
        public function counterAttack(Unit $enemy) {
            $newHp = $this->hitPoints - intval($enemy->damage / 2);
            
            if ( $newHp > 0 ) {
                $this->hitPoints = $newHp;
                return;
            }
            $this->hitPoints = 0;
        }
        
        public function __toString() {
            $out = "";
            
            $out .= "Unit name is: " . sprintf("%s", $this->name) . '.' . PHP_EOL;
            $out .= " details: " . PHP_EOL;
            $out .= "  * damage: " . sprintf("%d", $this->damage) . ';' . PHP_EOL;
            $out .= "  * hit points: " . sprintf("%d", $this->hitPoints) . ';' . PHP_EOL;
            $out .= "  * hit points limit: " . sprintf("%d", $this->hitPointsLimit) . '.' . PHP_EOL;
            
            return $out;
        }
    }
    
    $barbarian = new Unit("Barbarian", 50, 20);
    $knight = new Unit("Knight", 45, 25);
    
    echo "#######################" . PHP_EOL;
    echo $barbarian . PHP_EOL;
    echo $knight . PHP_EOL;
    
    $barbarian->attack($knight);
    $knight->attack($barbarian);
    $barbarian->attack($knight);
    
    echo "#######################" . PHP_EOL;
    echo $barbarian . PHP_EOL;
    echo $knight . PHP_EOL;
    
    try {
        $knight->addHitPoints(1); 
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
    
    $barbarian->addHitPoints(51);
    
    try {
        $knight->attack($barbarian);   
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
    
    echo "#######################" . PHP_EOL;
    echo $barbarian . PHP_EOL;
    echo $knight . PHP_EOL;
?>
