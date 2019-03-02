#include <stdio.h>

int main() {
    int numerator, denominator, multiple;
    
    scanf("%d %d", &numerator, &denominator);
    
    if ( denominator < 0 ) {
        denominator *= -1;
    }
    
    multiple = numerator - numerator % denominator;
    
    if ( multiple < numerator ) {
        multiple += denominator;
    }
    
    printf("%d\n", multiple);
}
