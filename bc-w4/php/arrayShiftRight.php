<?php
    function arrayShiftRight(&$array) {
        $size = count($array);
        $last = $size - 1;
        
        if ( $size > 0 ) {
            $temp = $array[$last];
            
            for ( $i = $last; $i > 0; $i-- ) {
                $array[$i] = $array[$i-1];
            }
            $array[0] = $temp;
        }
    }
    
    $array = range(1, 10);
    
    arrayShiftRight($array);
    
    echo implode(' ', $array) . PHP_EOL;
?>
