#include <stdio.h>

// Make array unique by shifting elements
int arrayUnique(int array[], int size) {
    int newSize = size;
    
    for ( int i = 0; i < newSize; i++ ) {
        int temp = array[i];
        
        for ( int j = i + 1; j < newSize; j++ ) {
            if ( array[j] == temp ) {
                int shift = 1;
                
                for ( int m = j + 1; array[m] == temp && m < newSize; m++ ) {
                    shift += 1;
                }
                for ( int k = j; k < newSize; k++ ) {
                    int m = k + shift;
                    
                    array[k] = array[m];
                }
                newSize -= shift;
            }
        }
    }
    return newSize;
}

// Make array unique by swapping elements to the tail(order changes)
int arrayUnique2(int array[], int size) {
    int newSize = size;
    int last;

    for ( int i = 0; i < newSize; i++ ) {
        int temp = array[i];

        for ( int j = i + 1; j < newSize; j++ ) {
            if ( array[j] == temp ) {
                array[j] = array[newSize-1];
                newSize -= 1;
            }
        }
    }

    last = newSize - 1;
    if ( array[last] == array[last-1] ) {
        newSize -= 1;
    }
    return newSize;
}

void printArray(int array[], int size) {
    int last = size - 1;
    
    printf("{");
    if (last > -1) {
        printf("%d", array[0]);
        if (last > 0) {
            printf(",");
            for (int i = 1; i < last; i++) {
                printf(" %d,", array[i]);
            }
            printf(" %d", array[last]);
        }
    }
    printf("};");
}

int main() {
    int size = 15;
    int newSize;
    // int array[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 5, 4, 3, 2, 1};
    // int array[] = {24, 1, 0, 6, 15, 15, 15, 23, 6, 1, 18, 345, 6, 6, 6, 15};
    int array[] = {1, 1, 2, 2, 3, 3, 4, 4, 6, 6, 6, -3, 5, 4, 3};

    printArray(array, size);
    printf("\n######################################\n");
    newSize = arrayUnique(array, size);
    printArray(array, newSize);
    printf("\nNew Size: %d\n", newSize);

    return 0;
}

/*
Задача arrayUnique()

Условие задачи
Написать функцию:
int arrayUnique(int array[], int size)

Удалить из массива дубликаты элементов. Вернуть новую длину массива.

Примечание: пример ввода и вывода показан для лучшего понимания условия задачи.
Выводить результат на печать не нужно.

Пример ввода
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 5 4 3 2 1
Пример вывода
array = 1 2 3 4 5 6 7 8 9 10
len = 10
*/
