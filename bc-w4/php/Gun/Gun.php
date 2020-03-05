<?php
    require_once(dirname(__FILE__) . '\exceptions.php');
    
    class Gun {
        private $amount;
        private $capacity;
        private $isReady;
        private $model;
        private $totalShots;
        
        public function validate($value) {
            if ( is_int($value) ) {
                return $value;
            }
            return new Exception("Invalid param");
        }
        
        public function __construct($model="Beretta", $capacity=8) {
            $this->model = $model;
            $this->capacity = $this->validate($capacity);
            $this->amount = 0;
            $this->isReady = false;
            $this->totalShots = 0;
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
        
        public function ready() {
            return $this->isReady;
        }
        
        public function prepare() {
            if ( !$this->isReady ) {
                $this->isReady = !$this->isReady;
            }
        }
        
        public function reload() {
            $this->amount = $this->capacity;
        }
        
        public function shoot() {
            if ( !$this->isReady ) {
                throw new NotReady("State error: not prepared to shoot");
            }
            if ( $this->amount == 0 ) {
                throw new OutOfRounds("State error: no bullets left");
            }
            $this->amount -= 1;
            $this->totalShots += 1;
            echo "Bang!" . PHP_EOL;
        }
        
        public function __toString() {
            $out = "";
            
            $out .= "Gun of model #" . sprintf("%s", $this->model) . '.' . PHP_EOL;
            $out .= " details:" . PHP_EOL;
            $out .= "  * magazine capacity: " . sprintf("%d", $this->capacity) . ';' . PHP_EOL;
            $out .= "  * bullets in magazine: " . sprintf("%d", $this->amount) . ';' . PHP_EOL;
            $out .= "  * is gun ready for usage: " . ($this->ready() ? "Yes" : "No") . ';' . PHP_EOL;
            $out .= "  * number of shots fired: " . sprintf("%d", $this->totalShots) . '.' . PHP_EOL;
            
            return $out;
        }
    }
    
    $beretta = new Gun;
    $colt = new Gun("Colt", 2);
    
    echo $beretta . PHP_EOL;
    echo $colt . PHP_EOL;
    
    $colt->reload();
    $colt->prepare();
    
    $colt->shoot();
    $colt->shoot();
    
    echo $beretta . PHP_EOL;
    echo $colt . PHP_EOL;
    
    try {
        $colt->shoot();
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
    try {
        $beretta->shoot();
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
    try {
        echo "\$nonexisting: " . $beretta->nonexisting . PHP_EOL;
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
    try {
        $beretta->model = "some text";
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
?>
