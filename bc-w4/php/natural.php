<?php
    $max = intval(fgets(STDIN));
    
    echo implode(' ', range(1, $max)) . PHP_EOL;
?>
