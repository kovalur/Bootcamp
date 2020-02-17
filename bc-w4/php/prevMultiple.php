<?php
    $numerator = intval(fgets(STDIN));
    $denominator = intval(fgets(STDIN));
    
    if ( $denominator < 0 ) {
        $denominator *= -1;
    }
    
    $multiple = $numerator - $numerator % $denominator;
    if ( $multiple > $numerator ) {
        $multiple -= $denominator;
    }
    
    echo $multiple . PHP_EOL;
?>
