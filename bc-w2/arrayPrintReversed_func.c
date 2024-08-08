#include <stdio.h>

void arrayPrintReversed(int array[], int size) {
    for ( int i = size - 1; i > 0; i-- ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[0]);
}

int main() {
    int size = 100;
    int array[size];
    
    for ( int i = 0; i < size; i++ ) {
        array[i] = i;
    }
    
    arrayPrintReversed(array, size);
    
    return 0;
}

/*
Задача arrayPrintReversed()

Условие задачи
Написать функцию:
void arrayPrintReversed(int array[], int size)

Распечатать массив на экран в строку через пробел в обратном порядке.
*/
