<?php
    require_once(dirname(__FILE__) . '\exceptions.php');
    
    class Pen {
        private $inkAmount;
        private $inkCapacity;
        
        private function validate($value) {
            if ( is_int($value) && $value > 0 ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($inkCapacity=4096) {
            $this->inkCapacity = $this->validate($inkCapacity);
            $this->inkAmount = $inkCapacity;
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
        
        public function write(Paper $paper, $message) {
            if ( $this->inkAmount == 0 ) {
                throw new OutOfInk("Action error: no ink left");
            }
            
            $beforePaperSymbols = $paper->symbols;
            if ( strlen($message) > $this->inkAmount ) {
                $paper->addContent(substr($message, 0, $this->inkAmount));
                $this->inkAmount -= $paper->symbols - $beforePaperSymbols;
                return;
            }
            $paper->addContent($message);
            $this->inkAmount -= $paper->symbols - $beforePaperSymbols;
        }
        
        public function refill() {
            $this->inkAmount = $this->inkCapacity;
        }
    }
?>
