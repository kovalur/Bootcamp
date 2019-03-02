#include <stdio.h>

int main() {
    int a;
    int toggle = 1;
    
    scanf("%d", &a);
    
    if ( a % 2 == 0 ) {
        printf("alpha\n");
        toggle = 0;
    }
    if ( a % 3 == 0 ) {
        printf("bravo\n");
        toggle = 0;
    }
    if ( a % 5 == 0 ) {
        printf("charlie\n");
        toggle = 0;
    }
    if ( toggle ) {
        printf("zulu\n");
    }
    
    return 0;
}
