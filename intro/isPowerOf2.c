#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    
    // -2 -1 0 | 1 2 | 3 4 | 5 6 | 7 8 | 9 10 11 12 | 13 14 15 16 17 18 19 20 21 22 23 24 252 6 27 28 29 30 31
    
    if ( number >= 1 && number % 2 == 0 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
