#include <stdio.h>

int main() {
    int x, base;
    int rate = 1;
    
    scanf("%d %d", &x, &base);
    
    for ( ; base * rate <= x; ) {
        rate *= base;
    }
    
    for ( ; rate > 1; ) {
        printf("%d", x/rate);
        if ( x / rate != 0 ) {
            x %= rate;
        }
        rate /= base;
    }
    printf("%d\n", x/rate);
    
    return 0;
}
