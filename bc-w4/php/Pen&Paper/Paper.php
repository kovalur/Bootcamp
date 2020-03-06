<?php
    require_once(dirname(__FILE__) . '\exceptions.php');
    
    class Paper {
        private $maxSymbols;
        private $symbols;
        private $content;
        
        private function validate($value) {
            if ( is_int($value) && $value > 0 ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($maxSymbols=4096) {
            $this->maxSymbols = $this->validate($maxSymbols);
            $this->symbols = 0;
            $this->content = "";
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
        
        public function addContent($message) {
            $spaceLeft = $this->maxSymbols - $this->symbols;
            $textToAdd = substr($message, 0, $spaceLeft);
            
            if ( $spaceLeft == 0 ) {
                throw new OutOfSpace("Action error: no space left");
            }
            
            $this->content .= $textToAdd;
            $this->symbols += strlen($textToAdd);
        }
        
        public function show() {
            echo $this->content . PHP_EOL;
        }
    }
?>
