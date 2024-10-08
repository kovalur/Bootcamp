#include <stdio.h>

void arrayReverse(int array[], int size) {
    for ( int i = 0, j = size - 1; i < j; i++, j-- ) {
        int temp = array[i];
        
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int last;
    
    arrayReverse(array, size);
    
    last = size - 1;
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
    return 0;
}

/*
Задача arrayReverse()

Условие задачи
Написать функцию:
void arrayReverse(int array[], int size)

Использование дополнительного массива не разрешается.
*/
