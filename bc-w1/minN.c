#include <stdio.h>

int main() {
    int length;
    int min;
    
    scanf("%d %d", &length, &min);
    for ( int current; length > 1; length-- ) {
        scanf("%d", &current);
        if ( current < min ) {
            min = current;
        }
    }
    printf("%d\n", min);
    
    return 0;
}

/*
Задача minN

Условие задачи
Считать с клавиатуры целое положительное число - количество чисел в
последовательности.
Затем считать с клавиатуры заданное количество чисел и вывести наименьшее из
них.
Данная задача решается без массивов.

Пример ввода
5
1 2 3 4 5
Пример вывода
1
*/
