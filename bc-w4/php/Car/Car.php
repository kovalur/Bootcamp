<?php
    require_once(dirname(dirname(__FILE__)) . '\Basic\Point.php');
    require_once(dirname(__FILE__) . '\exceptions.php');
    
    class Car {
        private $fuelAmount;
        private $fuelCapacity;
        private $fuelConsumption;
        private Point $location;
        private $model;
        
        public function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($capacity=60, $consumption=0.6, Point $location=null, $model="Mercedes") {
            if ( $location == null ) {
                $location = new Point(0, 0);
            }
            $this->fuelCapacity = $this->validate($capacity);
            $this->fuelConsumption = $this->validate($consumption);
            $this->location = $location;
            $this->model = $model;
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
        
        public function drive() {
            if ( func_num_args() == 2 ) {
                $destination = new Point($this->validate(func_get_arg(0)), $this->validate(func_get_arg(1)));
            } else if ( func_num_args() == 1 && func_get_arg(0) instanceof Point ) {
                $destination = func_get_arg(0);
            } else {
                throw new Exception("Invalid param");
            }
            
            $fuelNeeded = $this->location->distance($destination) * $this->fuelConsumption;
            
            if ( $fuelNeeded > $this->fuelCapacity ) {
                throw new OutOfFuel("Value error: fuel needed to reach destination exceeds capacity");
            }
            if ( $fuelNeeded > $this->fuelAmount ) {
                $this->refill($fuelNeeded - $this->fuelAmount);
            }
            $this->location = $destination;
            $this->fuelAmount -= $fuelNeeded;
        }
        
        public function refill($fuel) {
            $fuelAfterRefill = $this->fuelAmount + $this->validate($fuel);
            
            if ( $fuelAfterRefill > $this->fuelCapacity ) {
                throw new ToMuchFuel("Value error: too much fuel");
            }
            $this->fuelAmount = $fuelAfterRefill;
        }
        
        public function __toString() {
            $out = "";
            
            $out .= "Car of model #" . sprintf("%s", $this->model) . " is located at " . $this->location . '.' . PHP_EOL;
            $out .= " details:" . PHP_EOL;
            $out .= "  * fuel capacity, l: " . sprintf("%g", $this->fuelCapacity) . ';' . PHP_EOL;
            $out .= "  * fuel ammount, l: " . sprintf("%g", $this->fuelAmount) . ';' . PHP_EOL;
            $out .= "  * fuel consumption, l/km: " . sprintf("%g", $this->fuelConsumption) . '.';
            
            return $out;
        }
    }
    
    $car = new Car;
    
    echo $car . PHP_EOL;
    
    echo "#######################" . PHP_EOL;
    echo "Your max travel distance: "
        . sprintf("%g", (new Point(0, 0))->distance(new Point(50, 86.6025403784)) * $car->fuelConsumption)
        . "km." . PHP_EOL;
    
    try {
        $car->drive(50, 86.6025403785);
    } catch (Exception $e) {
        echo $e->getMessage(). PHP_EOL;
    }
    
    try {
        $car->refill(61);
    } catch (Exception $e) {
        echo $e->getMessage(). PHP_EOL;
    }
    
    $car->drive(new Point(5, 11));
    
    echo $car . PHP_EOL;
    
    try {
        echo "\$nonexisting: " . $car->nonexisting . PHP_EOL; 
    } catch (Exception $e) {
        echo $e->getMessage(). PHP_EOL;
    }
    try {
        $car->fuelAmount = "some text"; 
     } catch (Exception $e) {
        echo $e->getMessage(). PHP_EOL;
    }
?>
