#include <stdio.h>

int arraySum(int array[], int size) {
    int sum = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        sum += array[i];
    }
    return sum;
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int sum;
    
    sum = arraySum(array, size);
    printf("%d\n", sum);
    
    return 0;
}

/*
Задача arraySum()

Условие задачи
Написать функцию:
int arraySum(int array[], int size)

Вернуть сумму элементов массива.
size > 0
*/
