#include <stdio.h>

#define MULTIPLE 3

int main() {
    int min, max, step, minMultiple, maxMultiple;
    
    scanf("%d %d", &min, &max);
    
    if ( min == max && min % MULTIPLE != 0 ) {
        return 0;
    }
    
    minMultiple = min - min % MULTIPLE;
    maxMultiple = max - max % MULTIPLE;
    if ( min > max ) {
        step = -MULTIPLE;
        if ( minMultiple > min ) {
            minMultiple -= MULTIPLE;
        }
        if ( maxMultiple < max ) {
            maxMultiple += MULTIPLE;
        }
    } else {
        step = MULTIPLE;
        if ( minMultiple < min ) {
            minMultiple += MULTIPLE;
        }
        if ( maxMultiple > max ) {
            maxMultiple -= MULTIPLE;
        }
    }
    
    for ( int i = minMultiple; 1; i += step ) {
        printf("%d\n", i);
        
        if ( i == maxMultiple ) {
            return 0;
        }
    }
}
