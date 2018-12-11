#include <stdio.h>

int main() {
    int x;
    int aliquant = 1;
    
    scanf("%d", &x);
    
    if ( x % 2 == 0 ) {
        printf("alpha\n");
        aliquant = 0;
    }
    if ( x % 3 == 0 ) {
        printf("bravo\n");
        aliquant = 0;
    }
    if ( x % 5 == 0 ) {
        printf("charlie\n");
        aliquant = 0;
    }
    if ( aliquant ) {
        printf("zulu\n");
    }
    
    return 0;
}
