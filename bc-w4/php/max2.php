<?php 
    $x = intval(fgets(STDIN));
    $y = intval(fgets(STDIN));
    
    if ( $x > $y ) {
        echo $x . PHP_EOL;
    } else {
        echo $y . PHP_EOL;
    }
?>
