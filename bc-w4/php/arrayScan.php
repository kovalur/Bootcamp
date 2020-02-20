<?php
    function arrayScan(&$in, &$array, $limit) : int {
        $len = 0;
        
        while ( $len < $limit && ($line = fgets($in)) !== FALSE ) {
            $buffer = explode(' ', $line);
            
            for ( $i = 0; $i < count($buffer) && $len < $limit; $i++ ) {
                if ( intval($buffer[$i]) || $buffer[$i] == '0' ) {
                    $array[$len] = intval($buffer[$i]);
                    $len += 1;
                }
            }
        }
        
        return $len;
    }
    
    $in = fopen("task.in", "r");
    $array = array();
    $limit = 10;
    
    echo arrayScan($in, $array, $limit) . PHP_EOL;
    fclose($in);
    
    echo implode(' ', $array) . PHP_EOL;
?>
