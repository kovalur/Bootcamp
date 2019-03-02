#include <stdio.h>

int main() {
    int min, max;
    int multiple;
    
    scanf("%d %d", &min, &max);
    
    multiple = min - min % 2;
    
    if ( multiple < min ) {
        multiple += 2;
    }
    
    for ( ; multiple <= max - 2; multiple += 2 ) {
        printf("%d ", multiple*multiple);
    }
    printf("%d\n", multiple*multiple);
    
    return 0;
}
