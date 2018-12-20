#include <stdio.h>

int main() {
    int min, max, multiple;
    
    scanf("%d %d", &min, &max);
    
    if ( min % 2 != 0 ) {
        min += 1;
    }
    if ( max % 2 != 0 ) {
        max -= 1;
    }
    multiple = min;
    for ( ; multiple < max; multiple += 2 ) {
        printf("%d ", multiple);
    }
    printf("%d\n", multiple);
    
    return 0;
}
