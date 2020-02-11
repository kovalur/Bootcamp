<?php 
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $c = intval(fgets(STDIN));
    
    if ( $a > $b && $a > $c ) {
        echo $a . PHP_EOL;
    } else if ( $b > $a && $b > $c ) {
        echo $b . PHP_EOL;
    } else if ( $c > $a && $c > $b ) {
        echo $c . PHP_EOL;
    } else {
        echo $a . PHP_EOL;
    }
?>
