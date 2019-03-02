#include <stdio.h>

int main() {
    int base, exponent;
    int result = 1;
    
    scanf("%d %d", &base, &exponent);
    
    for ( int i = 0; i < exponent; i++ ) {
        printf("%d ", result);
        result *= base;
    }
    printf("%d\n", result);
    
    return 0;
}
