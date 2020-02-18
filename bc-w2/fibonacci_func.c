#include <stdio.h>

// int fibonacci(int n) {
//     if ( n == 0 ) {
//         return 0;
//     }
//     if ( n == 1 || n == -1 ) {
//         return 1;
//     }
//     if ( n < 0 ) {
//         return fibonacci(n+2) - fibonacci(n+1);
//     }
//     return fibonacci(n-1) + fibonacci(n-2);
// }

// Better solution (in my opinion),
// but does not meet valid "negafibonacci" sequence: −8, 5, −3, 2, −1, 1, 0.
// In this implementation: −8, -5, −3, -2, −1, -1, 0.
int fibonacci(int n) {
    if ( n == 0 ) {
        return 0;
    }
    if ( n == 1 ) {
        return 1;
    }
    if ( n == -1 ) {
        return -1;
    }
    if ( n < 0 ) {
        return fibonacci(n+1) + fibonacci(n+2);
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("%d\n", fibonacci(number));
    
    return 0;
}
