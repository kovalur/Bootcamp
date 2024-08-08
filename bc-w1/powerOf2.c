#include <stdio.h>

#define BASE 2

int main() {
    int exponent;
    int result = 1;
    
    scanf("%d", &exponent);
    
    for ( int i = 0; i < exponent; i++ ) {
        printf("%d ", result);
        result *= BASE;
    }
    printf("%d\n", result);
    
    return 0;
}

/*
Задача powerOf2

Условие задачи
Считать с клавиатуры целое неотрицательное число. Вывести через пробел степени
числа 2 от нулевой до заданной. Использовать цикл.

Пример ввода
3
Пример вывода
1 2 4 8
*/
