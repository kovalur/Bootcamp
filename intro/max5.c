#include <stdio.h>

int main() {
    int a, b, c, d, e, least;
    
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    least = a;
    
    if ( b > least ) {
        least = b;
    }
    if ( c > least ) {
        least = c;
    }
    if ( d > least ) {
        least = d;
    }
    if ( e > least ) {
        least = e;
    }
    printf("%d\n", least);
    
    return 0;
}
