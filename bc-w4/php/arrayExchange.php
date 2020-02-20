<?php
    function arrayExchange(&$array) {
        for ( $i = 1; $i < count($array); $i+=2 ) {
            $temp = $array[$i];
            $j = $i - 1;
            
            $array[$i] = $array[$j];
            $array[$j] = $temp;
        }
    }
    
    $array = array(0 => 'a', 1 => 'b', 2 => 'c', 3 => 'd', 4 => 'e', 5 => 'f', 6 => 'g');
    
    arrayExchange($array);
    
    echo implode(' ', $array) . PHP_EOL;
?>
