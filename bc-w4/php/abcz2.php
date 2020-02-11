<?php 
    $a = intval(fgets(STDIN));
    $toggle = 1;
    
    if ( $a % 2 == 0 ) {
        echo "alpha" . PHP_EOL;
        $toggle = 0;
    }
    if ( $a % 3 == 0 ) {
        echo "bravo" . PHP_EOL;
        $toggle = 0;
    }
    if ( $a % 5 == 0 ) {
        echo "charlie" . PHP_EOL;
        $toggle = 0;
    }
    if ( $toggle ) {
        echo "zulu" . PHP_EOL;
    }
?>
