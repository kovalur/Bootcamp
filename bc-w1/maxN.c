#include <stdio.h>

int main() {
    int length;
    int max;
    
    scanf("%d %d", &length, &max);
    
    for ( int current; length > 1; length-- ) {
        scanf("%d", &current);
        if ( current > max ) {
            max = current;
        }
    }
    printf("%d\n", max);
    
    return 0;
}
