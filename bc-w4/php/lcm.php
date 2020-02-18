<?php
    $in = fopen("task.in", "r");
    $out = fopen("task.out", "w");
    
    $numbers = explode(' ', fgets($in));
    fclose($in);
    
    $a = intval($numbers[0]);
    $b = intval($numbers[1]);
    
    $gcd = 1;
    $multiple = $a * $b;
    for ( ; $a > 0 && $b > 0; ) {
        $a %= $b;
        if ( $a != 0 ) {
            $b %= $a;
        }
        if ( $a == 0 ) {
            $gcd = $b;
        } else if ( $b == 0 ) {
            $gcd = $a;
        }
    }
    $lcm = $multiple / $gcd;
    
    fwrite($out, $lcm . PHP_EOL);
    fclose($out);
?>
