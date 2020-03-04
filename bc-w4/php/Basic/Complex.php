<?php
    class Complex {
        private $real;
        private $imaginary;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($real=0, $imaginary=0) {
            $this->real = $this->validate($real);
            $this->imaginary = $this->validate($imaginary);
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function equals(Complex $other) {
            return $this->real == $other->real && $this->imaginary == $other->imaginary;
        }
        
        public function incrementedBy(Complex $other) {
            $this->real += $other->real;
            $this->imaginary += $other->imaginary;
        }
        
        public function decrementedBy(Complex $other) {
            $this->real -= $other->real;
            $this->imaginary -= $other->imaginary;
        }
        
        public function plus(Complex $other) {
            $sumOfComplexes = new Complex;
            
            $sumOfComplexes->real = $this->real + $other->real;
            $sumOfComplexes->imaginary = $this->imaginary + $other->imaginary;
            
            return $sumOfComplexes;
        }
        
        public function minus(Complex $other) {
            $diffOfComplexes = new Complex;
            
            $diffOfComplexes->real = $this->real - $other->real;
            $diffOfComplexes->imaginary = $this->imaginary - $other->imaginary;
            
            return $diffOfComplexes;
        }
        
        public function multiply(Complex $other) {
            $multiplyOfComplexes = new Complex;
            
            $multiplyOfComplexes->real = $this->real * $other->real - $this->imaginary * $other->imaginary;
            $multiplyOfComplexes->imaginary = $this->real * $other->imaginary + $this->imaginary * $other->real;
            
            return $multiplyOfComplexes;
        }
        
        public function __toString() {
            if ( $this->imaginary == 0 ) {
                return sprintf("%g", $this->real);
            } else if ( $this->real == 0 ) {
                return sprintf("%g", $this->imaginary) . 'i';
            }
            return sprintf("%g%+g", $this->real, $this->imaginary) . 'i';
        }
    }
    
    $a = new Complex(-1.1, 2.2);
    $b = new Complex(1.2, -2.1);
    $c = new Complex();
    
    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    
    $c = clone $a;
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
    
    $c = $a->multiply($b);
    
    echo "c: " . $c . PHP_EOL;
?>
