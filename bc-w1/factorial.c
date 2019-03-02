#include <stdio.h>

int main() {
    int number;
    int factorial;
    
    scanf("%d", &number);
    
    factorial = number;
    for ( int i = number; i > 1; i-- ) {
        factorial *= (i - 1);
    }
    
    if ( number == 0 || number == 1 ) {
        printf("1\n");
    } else if ( number > 1 ) {
        printf("%d\n", factorial);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
