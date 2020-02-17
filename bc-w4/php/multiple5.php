<?php
    $multiple = 5;
    $max = intval(fgets(STDIN));
    $max -= $max % $multiple;
    
    echo implode(' ', range(0, $max, $multiple));
?>
