<?php
    $size = intval(fgets(STDIN));
    
    $counter = $size * $size;
    for ( $i = 0; $i < $size; $i++ ) {
        echo implode(' ', range($counter-$size+1, $counter, 1)) . PHP_EOL;
        $counter -= $size;
    }
?>
