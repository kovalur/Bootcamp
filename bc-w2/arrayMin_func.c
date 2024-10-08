#include <stdio.h>

int arrayMin(int array[], int size) {
    int min = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] < min ) {
            min = array[i];
        }
    }
    return min;
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int min;
    
    min = arrayMin(array, size);
    printf("%d\n", min);
    
    return 0;
}

/*
Задача arrayMin()

Условие задачи
Написать функцию:
int arrayMin(int array[], int size)

Вернуть значение минимального элемента в массиве.
*/
