<?php
    function arraySearch(&$array, $needle) : int {
        return ($key = array_search($needle, $array)) !== FALSE
                                                    ? $key : -1;
    }
    
    $array = array(0 => 2, 1 => -5, 2 => 0, 3 => 9, 4 => 2);
    
    echo arraySearch($array, 2) . PHP_EOL;
    echo arraySearch($array, 0) . PHP_EOL;
    echo arraySearch($array, 7) . PHP_EOL;
?>
