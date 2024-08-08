#include <stdio.h>

int main() {
    int base, exponent;
    int result = 1;
    
    scanf("%d %d", &base, &exponent);
    
    for ( int i = 0; i < exponent; i++ ) {
        printf("%d ", result);
        result *= base;
    }
    printf("%d\n", result);
    
    return 0;
}

/*
Задача powerOfX

Условие задачи
Считать с клавиатуры целое основание и целый неотрицательный показатель. Вывести
через пробел степени числа основания от нулевой до заданной.

Пример ввода
2 3
Пример вывода
1 2 4 8
*/
