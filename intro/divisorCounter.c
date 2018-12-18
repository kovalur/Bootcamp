#include <stdio.h>

int main() {
    int number;
    int counter = 1;
    
    scanf("%d", &number);
    
    if ( number > 1 ) {
        counter += 1;
    }
    
    for ( int i = 2; i <= number - 1; i++ ) {
        if ( number % i == 0 ) {
            counter += 1;
        }
    }
    printf("%d\n", counter);
    
    return 0;
}
