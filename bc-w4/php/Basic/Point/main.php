<?php
    require_once(dirname(__FILE__) . '\Point.php');
    
    $a = new Point(2, 5);
    $b = new Point(3, 7);
    $c = new Point(3, 7);
    $d = $a;
    $e = clone $a;
    $a->x = 7;
    echo $a->x . PHP_EOL;
    $a->x = 2;
    
    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    
    compare($a, $b);
    compare($b, $c);
    
    isTheSameInstance($a, $b);
    isTheSameInstance($a, $d);
    isTheSameInstance($e, $a);
    isTheSameInstance($b, $c);
    
    echo $a->distance($b) . PHP_EOL;
    echo $b->distance($c) . PHP_EOL;
?>
