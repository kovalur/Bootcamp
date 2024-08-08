#include <stdio.h>

int main() {
    int x;
    
    scanf("%d", &x);
    
    if ( x % 2 != 0 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}

/*
Задача isOdd

Условие задачи
Считать с клавиатуры целое число.
Если число нечётное, вывести на экран yes, в противном случае вывести no.

Пример ввода
17
Пример вывода
yes
*/
