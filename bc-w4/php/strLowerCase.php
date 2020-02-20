<?php
    function strLowerCase(&$str) {
        $str = strtolower($str);
    }
    
    $str = "MaKE Me LOWERcASE.";
    
    strLowerCase($str);
    
    echo $str . PHP_EOL;
?>
