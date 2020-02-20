<?php
    function arrayMin(&$array) : int {
        return min($array);
    }
    
    $array = array(0, -3, 21, 17, -3, 7);
    
    echo arrayMin($array) . PHP_EOL;
?>
