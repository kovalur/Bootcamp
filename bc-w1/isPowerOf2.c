#include <stdio.h>

// in-Work
int main() {
    int number;
    int result = 1;
    
    scanf("%d", &number);
    
    for ( ; result < number; result *= 2 );
    if ( result == number ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}

/*
Задача isPowerOf2

Условие задачи
Считать с клавиатуры целое положительное число. Если число является целой степенью двойки, вывести "yes", иначе вывести "no".

Пример ввода
8
Пример вывода
yes
*/
