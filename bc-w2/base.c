#include <stdio.h>

int main() {
    int number, base;
    int power = 1;
    
    scanf("%d %d", &number, &base);
    
    for ( int tmp = number / base; power <= tmp; power *= base );
    
    for ( ; power >= base; power /= base ) {
        printf("%d", number/power);
        number %= power;
    }
    
    printf("%d\n", number/power);
    
    return 0;
}
