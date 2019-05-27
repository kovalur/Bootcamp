#include <stdio.h>

int main() {
    int number;
    int member = 1;
    int k = 1;
    
    scanf("%d", &number);
    
    if ( number > 46 ) {
        return 0;
    }
    if ( number == 0 ) {
        member = 0;
    }
    if ( number < 0 && number % 2 == 0 ) {
        number *= -1;
        k *= -1;
    } else if ( number < 0 ) {
        number *= -1;
    }
    
    for ( int i = 1, j = member, k = 0; i < number; i++ ) {
        member = j + k;
        k = j;
        j = member;
    }
    printf("%d\n", member*k);
    
    return 0;
}
