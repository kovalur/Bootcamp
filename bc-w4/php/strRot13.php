<?php
    function strRot13(&$str) {
        $str = str_rot13($str);
    }
    
    $str = "Well done!";
    
    strRot13($str);
    
    echo  $str . PHP_EOL;
?>
