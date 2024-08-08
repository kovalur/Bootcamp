#include <stdio.h>

int main() {
    int number, base, ch;
    int power = 1;
    
    scanf("%d %d", &number, &base);
    
    if ( number < 0 ) {
        number = -number;
        printf("-");
    }
    
    for ( int temp = number / base; power <= temp; power *= base );
    
    for ( ; power >= base; power /= base ) {
        ch = number / power + 48;
        if ( ch > '9' ) {
            ch += 7;
        }
        printf("%c", ch);
        number %= power;
    }
    ch = number / power + 48;
    if ( ch > '9' ) {
        ch += 7;
    }
    printf("%c\n", ch);
    
    return 0;
}

/*
Задача base2

Условие задачи
Считать с клавиатуры целое число в десятичной системе счисления и основание
новой системы счисления (целое число от 2 до 36).
Вывести в консоль число, записанное в новой системе счисления.
В качестве цифр, превышающих 9, использовать заглавные буквы латинского
алфавита.
Для решения можно пользоваться только циклами. Задача решается без массивов.
Использовать только тип int.

Пример ввода
-255 16
Пример вывода
-FF
*/
