#include <stdio.h>

#define DIVISOR 5

int main() {
    int min, max;
    int multiple;
    
    scanf("%d %d", &min, &max);
    
    multiple = min - min % DIVISOR;
    if ( multiple < min ) {
        multiple += DIVISOR;
    }
    
    for ( ; multiple <= max; multiple += DIVISOR ) {
        printf("%d\n", multiple);
    }
    
    return 0;
}

/*
Задача div5

Условие задачи
Считать min, max. Вывести в столбик кратные пяти числа от min до max
включительно.

Пример ввода
0 15
Пример вывода
0
5
10
15
*/
