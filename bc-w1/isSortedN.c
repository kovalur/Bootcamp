#include <stdio.h>

int main() {
    int length;
    int sorted = 1;
    int current, previous;
    
    scanf("%d", &length);
    
    for ( int i = 1; i <= length; i++ ) {
        scanf("%d", &current);
        if ( current < previous && i > 1 ) {
            sorted = 0;
        }
        previous = current;
    }
    
    if ( sorted ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
