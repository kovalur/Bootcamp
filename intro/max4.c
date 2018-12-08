#include <stdio.h>

int main() {
    int a, b, c, d, least;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
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
    printf("%d\n", least);
    
    return 0;
}
