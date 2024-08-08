#include <stdio.h>

#define MULTIPLE 3
// #define MINABSOLUTE ((min < 0) ? (-1*min) : (min))
// #define MAXABSOLUTE ((max < 0) ? (-1*max) : (max))

int main() {
    int min, max, step, minMultiple, maxMultiple, minAbsolute, maxAbsolute;
    
    scanf("%d %d", &min, &max);
    
    if ( min < 0 ) {
        minAbsolute = -1 * min;
    } else {
        minAbsolute = min;
    }
    
    if ( max < 0 ) {
        maxAbsolute = -1 * max;
    } else {
        maxAbsolute = max;
    }
    
    if ( min == max && (min % MULTIPLE) != 0 ) {
        return 0;
    } else if ( min < max ) {
        step = MULTIPLE;
        if ( min > 0 && max > 0 ) {
            if ( maxAbsolute <= MULTIPLE - 1 ) {
                return 0;
            } else if ( maxAbsolute >= MULTIPLE ) {
                min += step;
            }
        } else if ( min < 0 && max < 0 ) {
            if ( minAbsolute <= MULTIPLE - 1 ) {
                return 0;
            } else if ( minAbsolute >= MULTIPLE ) {
                max -= step;
            }
        }
    } else if ( min > max ) {
        step = -MULTIPLE;
        if ( min > 0 && max > 0 ) {
            if ( minAbsolute <= MULTIPLE - 1 ) {
                return 0;
            } else if ( minAbsolute >= MULTIPLE ) {
                max -= step;
            }
        } else if ( min < 0 && max < 0 ) {
            if ( maxAbsolute <= MULTIPLE - 1 ) {
                return 0;
            } else if ( maxAbsolute >= MULTIPLE ) {
                min += step;
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

/*
Задача div3

Условие задачи
Считать min, max. Вывести в столбик кратные тройке числа от min до max включительно.

Пример ввода
0 9
Пример вывода
0
3
6
9
*/
