#include <stdio.h>

void sliceShiftLeft(int array[], int start, int end) {
    if ( start < end ) {
        int temp = array[start];
        
        for ( int i = start; i < end; i++ ) {
            array[i] = array[i+1];
        }
        array[end] = temp;
    }
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int start = 9;
    int end = 0;
    int last = size - 1;
    
    sliceShiftLeft(array, start, end);
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
    return 0;
}

/*
Задача sliceShiftLeft()

Условие задачи
Написать функцию:
void sliceShiftLeft(int array[], int start, int end)

Осуществить циклический сдвиг части массива на один элемент влево от start до
end включительно.
*/
