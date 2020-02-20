<?php
    function arrayShiftLeft(&$array) {
        $size = count($array);
        
        if ( $size > 0 ) {
            $temp = $array[0];
            
            for ( $i = 1; $i < $size; $i++ ) {
                $array[$i-1] = $array[$i];
            }
            $array[$size-1] = $temp;
        }
    }
    
    $array = range(1, 10);
    
    arrayShiftLeft($array);
    
    echo implode(' ', $array) . PHP_EOL;
?>
