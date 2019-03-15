#include <stdio.h>

int factorial(int n) {
    if ( n < 2 ) {
        if ( n < 0 ) {
            return -1;
        }
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("%d\n", factorial(number));
    
    return 0;
}
