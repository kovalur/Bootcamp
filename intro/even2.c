#include <stdio.h>

int main() {
    int min, max;
    int multiple;
    
    scanf("%d %d", &min, &max);
    
    if ( min % 2 != 0 ) {
        min += 1;
    }
    
    multiple = min;
    for ( ; multiple <= max - 2; multiple += 2 ) {
        printf("%d ", multiple);
    }
    printf("%d\n", multiple);
    
    return 0;
}
