<?php
    $max = intval(fgets(STDIN));
    $divisor = intval(fgets(STDIN));
    
    $max -= $max % $divisor;
    
    echo implode(' ', range(0, $max, $divisor));
?>
