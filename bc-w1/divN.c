#include <stdio.h>

int main() {
    int min, max, divisor;
    int multiple;
    
    scanf("%d %d %d", &min, &max, &divisor);
    
    multiple = min - min % divisor;
    if ( multiple < min ) {
        multiple += divisor;
    }
    
    for ( ; multiple <= max; multiple += divisor ) {
        printf("%d\n", multiple);
    }
    
    return 0;
}

/*
Задача divN

Условие задачи
Считать с клавиатуры целые числа min, max и положительный делитель. Вывести в столбик числа, кратные делителю, от min до max включительно.

Пример ввода
0 8 2
Пример вывода
0
2
4
6
8
*/
