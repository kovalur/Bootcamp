<?php
    function strUpperCase(&$str) {
        $str = strtoupper($str);
    }
    
    $str = "mAke mE upperCase.";
    
    strUpperCase($str);
    
    echo $str . PHP_EOL;
?>
