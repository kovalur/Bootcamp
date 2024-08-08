#include <stdio.h>

// in-Work (not finished!)
int main() {
    int number, base;
    FILE *out = fopen("task.out", "w");
    
    scanf("%d %d", &number, &base);
    
    for ( int temp = number / base; temp != 0; temp = number / base) {
        fprintf(out, "%d ", number-temp*base);
        number = temp * base;
    }
    fclose(out);
    
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
