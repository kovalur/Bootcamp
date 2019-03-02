#include <stdio.h>

int main() {
    int length;
    int min;
    
    scanf("%d %d", &length, &min);
    for ( int current; length > 1; length-- ) {
        scanf("%d", &current);
        if ( current < min ) {
            min = current;
        }
    }
    printf("%d\n", min);
    
    return 0;
}
