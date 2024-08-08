#include <stdio.h>

int main() {
    int length;
    int max;
    
    scanf("%d %d", &length, &max);
    
    for ( int current; length > 1; length-- ) {
        scanf("%d", &current);
        if ( current > max ) {
            max = current;
        }
    }
    printf("%d\n", max);
    
    return 0;
}

/*
Задача maxN

Условие задачи
Считать с клавиатуры целое положительное число - количество чисел в
последовательности.
Затем считать с клавиатуры заданное количество чисел и вывести наибольшее из
них.

Пример ввода
5
1 2 3 4 5
Пример вывода
5
*/
