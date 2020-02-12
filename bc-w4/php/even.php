<?php
    $max = intval(fgets(STDIN));
    
    if ( $max % 2 != 0 ) {
        $max -= 1;
    }
    
    $out = '';
    for ( $i = 0; $i < $max; $i += 2 ) {
        $out .= $i . ' ';
    }
    echo $out . $max . PHP_EOL;
?>
