#include <stdio.h>

int arrayMax(int array[], int size) {
    int max = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] > max ) {
            max = array[i];
        }
    }
    return max;
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int max;
    
    max = arrayMax(array, size);
    printf("%d\n", max); 
    
    return 0;
}

/*
Задача arrayMax()

Условие задачи
Написать функцию:
int arrayMax(int array[], int size)

Вернуть значение максимального элемента в массиве.
*/
