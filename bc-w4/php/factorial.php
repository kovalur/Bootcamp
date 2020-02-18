<?php
    function factorial($n) {
        if ( $n < 0 ) {
            return -1;
        }
        if ( $n <= 1 ) {
            return 1;
        }
        return $n * factorial($n-1);
    }
    
    $member = intval(fgets(STDIN));
    
    echo factorial($member) . PHP_EOL;
?>
