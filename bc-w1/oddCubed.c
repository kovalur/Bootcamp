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

/*
Задача oddCubed

Условие задачи
Считать с клавиатуры целые числа min и max. Вывести в строку кубы всех нечетных чисел в промежутке от min до max включительно. В указаном промежутке гарантированно существует минимум одно нечетное число.

Пример ввода
0 7
Пример вывода
1 27 125 343
*/
