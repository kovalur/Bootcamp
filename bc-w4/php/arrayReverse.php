<?php
    function arrayReverse(&$array) {
        for ( $i = 0, $j = count($array) - 1; $i < $j; $i++, $j-- ) {
            $temp = $array[$i];
            
            $array[$i] = $array[$j];
            $array[$j] = $temp;
        }
    }
    
    $array = range(-10, 10);
    
    arrayReverse($array);
    
    echo implode(' ', $array) . PHP_EOL;
?>
