<?php
    $x = intval(fgets(STDIN));
    $y = intval(fgets(STDIN));
    
    if ( $x <= $y ) {
        echo "alpha" . PHP_EOL;
    } else if ( $x < 0 ) {
        echo "bravo" . PHP_EOL;
    } else if ( $y == 0 ) {
        echo "charlie" . PHP_EOL;
    } else {
        echo "zulu" . PHP_EOL;
    }
?>
