#include <stdio.h>

int powerOf2(int exponent) {
    return 1 << exponent;
}

int main() {
    int exponent, result;
    
    scanf("%d", &exponent);
    
    result = powerOf2(exponent);
    printf("%d\n", result);
    
    return 0;
}
