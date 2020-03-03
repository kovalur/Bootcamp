<?php
    class Point {
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
                return $this->name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                $this->name = $this->validate($value);
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function distance(Point $other) {
            return hypot($this->x-$other->x, $this->y-$other->y);
        }
        
        public function __toString() {
            return sprintf("(%g, %g)", $this->x, $this->y);
        }
    }
    
    function compare($a, $b) {
        if ( $a == $b ) {
            echo $a . " is equal to " . $b . PHP_EOL;
        } else {
            echo $a . " is not equal to " . $b . PHP_EOL;
        }
    }
    
    function isTheSameInstance($a, $b) {
        if ( $a === $b ) {
            echo $a . " is references to the same instance" . PHP_EOL;
        } else {
            echo $a . " and " . $b . " is different instances" . PHP_EOL;
        }
    }
    
    $a = new Point(2, 5);
    $b = new Point(3, 7);
    $c = new Point(3, 7);
    $d = $a;
    $e = clone $a;
    
    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    
    compare($a, $b);
    compare($b, $c);
    
    isTheSameInstance($a, $b);
    isTheSameInstance($a, $d);
    isTheSameInstance($e, $a);
    isTheSameInstance($b, $c);
    
    echo $a->distance($b) . PHP_EOL;
    echo $b->distance($c) . PHP_EOL;
?>
