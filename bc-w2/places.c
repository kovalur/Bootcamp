#include <stdio.h>

int main() {
    int x;
    int counter = 0;
    
    scanf("%d", &x);
    
    if ( x <= 0 ) {
        counter += 1;
        x *= -1;
    }
    
    for ( ; x != 0; ) {
        x /= 10;
        counter += 1;
    }
    
    printf("%d\n", counter);
    
    return 0;
}

/*
Задача places

Условие задачи
Считать с клавиатуры целое число.
Вывести на экран количество знакомест, нужных для вывода этого числа.

Пример ввода
123
Пример вывода
3
*/
