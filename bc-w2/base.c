#include <stdio.h>

int main() {
    int number, base;
    int power = 1;
    
    scanf("%d %d", &number, &base);
    
    for ( int tmp = number / base; power <= tmp; power *= base );
    
    for ( ; power >= base; power /= base ) {
        printf("%d", number/power);
        number %= power;
    }
    
    printf("%d\n", number/power);
    
    return 0;
}

/*
Задача base

Условие задачи
Считать с клавиатуры целое неотрицательное число в десятичной системе счисления
и основание новой системы счисления (целое число от 2 до 10).
Вывести в консоль число, записанное в новой системе счисления.
Задача решается без массивов.

Пример ввода
8 3
Пример вывода
22
*/
