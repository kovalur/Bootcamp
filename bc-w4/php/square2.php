<?php
    $size = intval(fgets(STDIN));
    
    $counter = 1;
    for ( $i = 0; $i < $size; $i++ ) {
        echo implode(' ', range($counter, $counter+$size-1, 1)) . PHP_EOL;
        $counter += $size;
    }
?>
