#include <stdio.h>

#define MULTIPLE 3

int main() {
    int min, max, step, minMultiple, maxMultiple, maxAbsolute, minAbsolute;
    
    scanf("%d %d", &min, &max);
    
    if ( min == max && min % MULTIPLE != 0 ) {
        return 0;
    }
    
    if ( max < 0 ) {
        maxAbsolute = -1 * max;
    } else {
        maxAbsolute = max;
    }
    
    if ( min < 0 ) {
        minAbsolute = -1 * min;
    } else {
        minAbsolute = min;
    }
    
    if ( min > max ) {
        step = -MULTIPLE;
    } else {
        step = MULTIPLE;
    }
    if ( minAbsolute <= MULTIPLE - 1 ) {
        if ( maxAbsolute <= MULTIPLE - 1 ) {
            if ( min < 0 && max < 0 ) {
                return 0;
            } else if ( min > 0 && max > 0 ) {
                return 0;
            }
        }
    }
    if ( minAbsolute <= MULTIPLE - 1 ) {
        if ( maxAbsolute >= MULTIPLE && minAbsolute > 0 ) {
            if ( min < max && min > 0 ) {
                min += step;
            } else if ( min > max && min < 0 ) {
                min += step;
            }
        }
    }
    if ( maxAbsolute <= MULTIPLE - 1 ) {
        if ( minAbsolute >= MULTIPLE && maxAbsolute > 0 ) {
            if ( max > min && min < 0 ) {
                max -= step;
            }
            if ( max < min && min > 0 ) {
                max -= step;
            }
        }
    }
    
    minMultiple = min - min % MULTIPLE;
    maxMultiple = max - max % MULTIPLE;
    
    for ( int i = minMultiple; 1; i += step ) {
        printf("%d\n", i);
        
        if ( i == maxMultiple ) {
            return 0;
        }
    }
}
