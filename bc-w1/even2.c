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

/*
Задача even2

Условие задачи
Считать с клавиатуры два целых числа.
Вывести в строку все чётные числа в промежутке от первого до второго
включительно.
В указанном промежутке гарантировано наличие хотя бы одного числа, подлежащего
выводу.

Пример ввода
7 15
Пример вывода
8 10 12 14
*/
