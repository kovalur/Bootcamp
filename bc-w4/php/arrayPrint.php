<?php
    function arrayPrint(&$out, &$array) {
        $result = implode(' ', $array) . PHP_EOL;
        fwrite($out, $result);
    }
    
    $out = fopen("task.out", "w");
    $array = range(-10, 10, 2);
    
    arrayPrint($out, $array);
    fclose($out);
?>
