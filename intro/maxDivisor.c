#include <stdio.h>

int main() {
    int x;
    
    scanf("%d", &x);
    
    if ( x % 2 == 0 ) {
        printf("%d\n", x/2);
    } else if ( x % 3 == 0 ) {
        printf("%d\n", x/3);
    } else {
        printf("%d\n", 0);
    }
    
    return 0;
}
