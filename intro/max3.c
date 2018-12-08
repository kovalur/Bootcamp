#include <stdio.h>

int main() {
    int a, b, c, least;
    
    scanf("%d %d %d", &a, &b, &c);
    
    least = a;
    
    if ( b > least ) {
        least = b;
    }
    if ( c > least ) {
        least = c;
    }
    printf("%d\n", least);
    
    return 0;
}
