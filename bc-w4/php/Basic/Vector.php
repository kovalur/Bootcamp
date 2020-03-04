<?php
    class Vector {
        private $x;
        private $y;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($x=0, $y=0) {
            $this->x = $this->validate($x);
            $this->y = $this->validate($y);
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                $this->$name = $this->validate($value);
                return;
            }
            throw new Exception("Attribute error: attribute $name not found"); 
        }
        
        public function len() {
            return hypot($this->x, $this->y);
        }
        
        public function equals(Vector $other) {
            return $this->x == $other->x && $this->y == $other->y;
        }
        
        public function isTheSameInstance(Vector $other) {
            return $this === $other;
        }
        
        public function incrementedBy(Vector $other) {
            $this->x += $other->x;
            $this->y += $other->y;
        }
        
        public function decrementedBy(Vector $other) {
            $this->x -= $other->x;
            $this->y -= $other->y;
        }
        
        public function plus(Vector $other) {
            $sumOfVectors = new Vector;
            
            $sumOfVectors->x = $this->x + $other->x;
            $sumOfVectors->y = $this->y + $other->y;
            
            return $sumOfVectors;
        }
        
        public function minus(Vector $other) {
            $diffOfVectors = new Vector;
            
            $diffOfVectors->x = $this->x - $other->x;
            $diffOfVectors->y = $this->y - $other->y;
            
            return $diffOfVectors;
        }
        
        public function __toString() {
            return sprintf("(%g, %g)", $this->x, $this->y);
        }
    }
    
    $a = new Vector(1.1, 5.0);
    $b = new Vector(5, 1.1);
    $c = new Vector;
    
    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    
    $a->x = 2.0;
    
    echo "\$a->x: " . $a->x . PHP_EOL;
    
    $a->x = 1.1;
    
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    
    print "Length of a: " . $a->len() . PHP_EOL;
    
    $c = clone $a;
    
    echo ($a->isTheSameInstance($c) ? $a . " is references to the same instance"
                                    : $a . " and " . $c . " is different instances") . PHP_EOL;
    
    $a->incrementedBy($b);
    
    if ( !$a->equals($b) ) {
        echo $a . " is not equal to " . $b . PHP_EOL;
    } else if ( $a->equals($b) ) {
        echo $a . " is equal to " . $b . PHP_EOL;
    }
    
    $b->incrementedBy($c);
    
    $a->decrementedBy($c);
    $b->decrementedBy($a);
    $c = clone $a->plus($b);
    
    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    
    $c = $a->minus($b);
    
    echo "c: " . $c . PHP_EOL;
?>
