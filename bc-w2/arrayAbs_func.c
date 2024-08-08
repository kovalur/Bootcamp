#include <stdio.h>

void arrayAbs(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
    }
}

int main() {
    int size = 100;
    int array[size];
    
    for ( int i = 0; i < size; i++ ) {
        if ( i % 2 ) {
            array[i] = -1 * i;
        } else {
            array[i] = i;
        }
    }
    
    arrayAbs(array, size);
    
    return 0;
}

/*
Задача arrayAbs()

Условие задачи
void arrayAbs(int array[], int size)

Заменить каждый элемент массива его абсолютным значением.
*/
