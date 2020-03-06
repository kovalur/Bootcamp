<?php
    class _Countable {
        private static $count = 0;
        
        public function __construct() {
            self::$count += 1;
        }
        
        public function __destruct() {
            self::$count -= 1;
        }
        
        public function __set($name, $value) {
            throw new Exception("Action error: attribute change not allowed");
        }
        
        public static function getCount() {
            return self::$count;
        }
    }
    
    echo "##########################" . PHP_EOL;
    echo "Total count: " . _Countable::getCount() . PHP_EOL;
    
    $c1 = new _Countable;
    $c2 = new _Countable;
    $c3 = new _Countable;
    
    echo "##########################" . PHP_EOL;
    echo "Total count: " . _Countable::getCount() . PHP_EOL;
    
    unset($c1);
    unset($c3);
    
    echo "##########################" . PHP_EOL;
    echo "Total count: " . _Countable::getCount() . PHP_EOL;
?>
