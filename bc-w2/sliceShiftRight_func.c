#include <stdio.h>

void sliceShiftRight(int array[], int start, int end) {
    if ( end > start ) {
        int temp = array[end];
        
        for ( int index = end; index > start; index-- ) {
            array[index] = array[index-1];
        }
        array[start] = temp;
    }
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int start = 7;
    int end = 3;
    int last = size - 1;
    
    sliceShiftRight(array, start, end);
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
    return 0;
}

/*
Задача sliceShiftRight()

Условие задачи
Написать функцию:
void sliceShiftRight(int array[], int start, int end)

Осуществить циклический сдвиг части массива на один элемент вправо от start до
end включительно.
*/
