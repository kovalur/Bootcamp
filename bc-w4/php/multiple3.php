<?php
    $multiple = 3;
    $max = intval(fgets(STDIN));
    $max -= $max % $multiple;
    
    echo implode(' ', range(0, $max, $multiple));
?>
