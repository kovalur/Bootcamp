#include <stdio.h>

#define MULTIPLE 3

int main() {
    int max;
    
    scanf("%d", &max);
    
    max = max - max % MULTIPLE;
    
    for ( int i = 0; i < max; i += MULTIPLE ) {
        printf("%d ", i);
    }
    printf("%d\n", max);
    
    return 0;
}

/*
Задача multiple3
Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все числа, кратные 3, от нуля до указанного числа включительно.

Пример ввода
17
Пример вывода
0 3 6 9 12 15
*/
