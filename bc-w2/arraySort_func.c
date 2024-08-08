#include <stdio.h>

void arraySort(int array[], int size) {
    for ( int sorted = 0; sorted == 0; ) {
        sorted = 1;
        for ( int i = 0, j = 1; j < size; i++, j++ ) {
            int current = array[i];
            int next = array[j];
            
            if ( current > next ) {
                array[j] = current;
                array[i] = next;
                sorted = 0;
            }
        }
    }
}

int main() {
    int size = 10;
    int array[] = {4, 3, 2, 1, 0, -1, -2, -3, -4, -5, '\0'};
    int last = size - 1;

    arraySort(array, size);

    printf("{");
    for ( int i = 0; i < last; i++ ) {
        printf("%d, ", array[i]);
    }
    printf("%d}", array[last]);

    return 0;
}

/*
Задача arraySort()

Условие задачи
Написать функцию:
void arraySort(int array[], int size)

Отсортировать элементы в порядке неубывания.
Настоятельно рекомендуется разработать алгоритм самостоятельно, без помощи гугла.
*/
