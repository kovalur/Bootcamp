#include <stdio.h>

int main() {
    int number;
    int factorial;
    
    scanf("%d", &number);
    
    factorial = number;
    for ( int i = number; i > 1; i-- ) {
        factorial *= (i - 1);
    }
    
    if ( number == 0 || number == 1 ) {
        printf("1\n");
    } else if ( number > 1 ) {
        printf("%d\n", factorial);
    } else {
        printf("-1\n");
    }
    
    return 0;
}

/*
Задача evenSquare

Условие задачи
Вычислить и вывести факториал считанного с клавиатуры целого числа. Гарантируется, что вводимое число не превышает 10.
В случае неопределенности ответа вывести -1.
Для решения пользоваться циклами.

Пример ввода
5
Пример вывода
120
*/
