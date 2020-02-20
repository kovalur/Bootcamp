<?php
    function arrayCopy(&$destination, &$source) {
        $destination = $source;
    }
    
    $destination = array();
    $source = range(-10, 10);
    
    arrayCopy($destination, $source);
    
    echo implode(' ', $destination) . PHP_EOL;
?>
