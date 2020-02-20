<?php
    function arrayMax(&$array) : int {
        return max($array);
    }
    
    $array = [4, -7, 10, 12, 0, -4, 15];
    
    echo arrayMax($array) . PHP_EOL;
?>
