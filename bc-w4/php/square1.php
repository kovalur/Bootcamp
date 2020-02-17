<?php
    $size = intval(fgets(STDIN));
    
    for ( $i = 0; $i < $size; $i++ ) {
        echo implode(' ', range(1, $size, 1)) . PHP_EOL;
    }
?>
