<?php
    class Identifiable {
        private $id;
        
        public function __construct() {
            $this->id = bin2hex(random_bytes(15));
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
    }
    
    $id1 = new Identifiable;
    $id2 = new Identifiable;
    
    echo "##########################" . PHP_EOL;
    echo "(1) => " . $id1->id . PHP_EOL;
    echo "(2) => " . $id2->id . PHP_EOL;
    
    $id3 = new Identifiable;
    $id4 = new Identifiable;
    
    echo "##########################" . PHP_EOL;
    echo "(3) => " . $id3->id . PHP_EOL;
    echo "(4) => " . $id4->id . PHP_EOL;
?>
