<?php
    require_once(dirname(__FILE__) . '\Paper.php');
    require_once(dirname(__FILE__) . '\Pen.php');
    
    $paper = new Paper(14);
    $pen = new Pen(18);
    
    echo "Paper max symbols: " . $paper->maxSymbols . PHP_EOL;
    echo "Paper symbols: " . $paper->symbols . PHP_EOL;
    echo "Pen ink amount: " . $pen->inkAmount . PHP_EOL;
    echo "Pen ink capacity: " . $pen->inkCapacity . PHP_EOL;
    
    $pen->write($paper, "Hello, world!");
    
    echo "##########################" . PHP_EOL;
    echo "Paper max symbols: " . $paper->maxSymbols . PHP_EOL;
    echo "Paper symbols: " . $paper->symbols . PHP_EOL;
    echo "Pen ink amount: " . $pen->inkAmount . PHP_EOL;
    echo "Pen ink capacity: " . $pen->inkCapacity . PHP_EOL;
    
    echo "##########################" . PHP_EOL;
    try {
        $pen->write($paper, "!!");
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
    
    echo "Pen ink amount: " . $pen->inkAmount . PHP_EOL;
    echo "Paper symbols: " . $paper->symbols . PHP_EOL;
    
    $paper->show();
    
    echo "##########################" . PHP_EOL;
    echo "Pen ink amount: " . $pen->inkAmount . PHP_EOL;
    
    $pen->refill();
    echo "Pen ink amount: " . $pen->inkAmount . PHP_EOL;
    
    try {
        $pen->write($paper, "!");
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
    
    $paper->show();
?>
