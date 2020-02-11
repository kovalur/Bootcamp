<?php 
    $x = intval(fgets(STDIN));
    $y = intval(fgets(STDIN));
    $z = intval(fgets(STDIN));
    
    if ( $x + $y > $z ) {
        echo "alpha" . PHP_EOL;
    } else if ( $x < $y - $z ) {
        echo "bravo" . PHP_EOL;
    } else if ( $y % $z == 0 ) {
        echo "charlie" . PHP_EOL;
    } else {
        echo "zulu" . PHP_EOL;
    }
?>
