#include <stdio.h>

#define MULTIPLE 5

int main() {
    int max;
    
    scanf("%d", &max);
    
    max = max - max % MULTIPLE;
    
    for ( int i = 0; i < max; i += MULTIPLE ) {
        printf("%d ", i);
    }
    
    printf("%d\n", max);
}

/*
Задача multiple5
Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все числа, кратные 5, от нуля до указанного числа включительно.

Пример ввода
17
Пример вывода
0 5 10 15
*/
