<?php
    function _strLen(&$str) : int {
        return iconv_strlen($str,'UTF-8');
    }
    
    $str = "Hi! I'm a string.";
    
    echo _strLen($str) . PHP_EOL;
?>
