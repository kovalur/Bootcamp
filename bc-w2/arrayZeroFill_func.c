#include <stdio.h>

#define MAX_SIZE 100

void arrayZeroFill(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        array[i] = 0;
    }
}

int main() {
    int size = MAX_SIZE;
    int array[size];
    
    arrayZeroFill(array, size);
    
    return 0;
}

/*
Задача arrayZeroFill()

Условие задачи
Написать функцию:
void arrayZeroFill(int array[], int size)

Заполнить массив нулями.
*/
