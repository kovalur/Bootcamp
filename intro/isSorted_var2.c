#include <stdio.h>

int main() {
    int a, b, c, d, e;
    int isOrdered = 1;
    
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if ( a > b ) {
        isOrdered = 0;
    } else if ( b > c ) {
        isOrdered = 0;
    } else if ( c > d ) {
        isOrdered = 0;
    } else if ( d > e ) {
        isOrdered = 0;
    }
    if ( isOrdered ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
