#include <stdio.h>

int main() {
    int number;
    int result = 1;
    
    scanf("%d", &number);
    
    for ( ; result < number; result *= 2 );
    if ( result == number ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
