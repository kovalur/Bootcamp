#include <stdio.h>

int main() {
    int min, max;
    int multiple, cubedMultiple;
    
    scanf("%d %d", &min, &max);
    
    if ( min % 2 == 0 ) {
        multiple = min + 1;
    } else {
        multiple = min;
    }
    
    for ( ; multiple <= max - 2; multiple += 2 ) {
        cubedMultiple = multiple * multiple * multiple;
        printf("%d ", cubedMultiple);
    }
    cubedMultiple = multiple * multiple * multiple;
    printf("%d\n", cubedMultiple);
    
    return 0;
}
