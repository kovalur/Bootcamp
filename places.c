#include <stdio.h>

int main() {
    int x;
    int count = 0;
    
    scanf("%d", &x);
    
    if ( x <= 0 ) {
        count += 1;
        x *= -1;
    }
    
    for ( ; x != 0; count++ ) {
        x /= 10;
    }
    
    printf("%d\n", count);
    
    return 0;
}
