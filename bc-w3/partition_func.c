#include <stdio.h>

#define SIZE 7

int partition(int array[], int start, int end) {
    int pivot = start + (end - start) / 2;
    int i = start - 1;
    int temp = array[end];
    
    array[end] = array[pivot];
    array[pivot] = temp;
    
    for ( int j = start; j < end; j++ ) {
        if ( array[j] <= array[end] ) {
            i += 1;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    i += 1;
    temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    
    return i;
}

void printArray(int array[], int size) {
    int last = size - 1;

    printf("{");
    for ( int i = 0; i < last; i++ ) {
        printf("%d, ", array[i]);
    }
    if ( size > 0 ) {
        printf("%d}\n", array[last]);
    } else {
        printf("}\n");
    } 
}

int main() {
    int array[SIZE] = {10, 80, 30, 90, 40, 50, 70};
    int start = 0;
    int end = SIZE - 1;
    int pivot;
    
    printArray(array, SIZE);
    printf("\n");
    
    pivot = partition(array, start, end);
    
    printArray(array, SIZE);
    printf("%d\n", pivot);
    
    return 0;
}

/*
Задача partition()

Условие задачи
int partition(int array[], int start, int end)

В качестве опорного элемента брать среднее арифметическое между start и end с
округлением вниз.
*/
