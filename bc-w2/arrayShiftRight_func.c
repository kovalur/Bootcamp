#include <stdio.h>

void arrayShiftRight(int array[], int size) {
    int index = size - 1;
    int temp = array[index];
    
    for ( ; index > 0; index-- ) {
        array[index] = array[index-1];
    }
    array[0] = temp;
}

int main () {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int last = size - 1;

    arrayShiftRight(array, size);

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);

    return 0;
}

/*
Задача arrayShiftRight()

Условие задачи
Написать функцию:
void arrayShiftRight(int array[], int size)

Реализовать циклический сдвиг массива на 1 элемент вправо.
Использование дополнительного массива не разрешается.
*/
