#include <stdio.h>

#define BASE 2

int main() {
    int exponent;
    int result = 1;
    
    scanf("%d", &exponent);
    
    for ( int i = 0; i < exponent; i++ ) {
        printf("%d ", result);
        result *= BASE;
    }
    printf("%d\n", result);
    
    return 0;
}
