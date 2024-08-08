#include <stdio.h>

#define SIZE 3

void matrixRotate270(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0, cot = size - 1; col < size; col++, cot-- ) {
            target[row][col] = source[cot][row];
        }
    }
}

void matrixFillWithNaturalNumbers(int matrix[SIZE][SIZE], int size) {
    for ( int counter = 1, row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            matrix[row][col] = counter;
            counter += 1;
        }
    }
}

void matrixPrint(int matrix[SIZE][SIZE], int size) {
    int last = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < last; col++ ) {
            printf("%d ", matrix[row][col]);
        }
        printf("%d\n", matrix[row][last]);
    }
}

int main() {
    int size = SIZE;
    int source[size][size];
    int target[size][size];
    
    matrixFillWithNaturalNumbers(source, size);
    matrixPrint(source, size);
    matrixRotate270(target, source, size);
    printf("------------------------------\n");
    matrixPrint(target, size);
    
    return 0;
}

/*
Задача matrixRotate270()

Условие задачи
void matrixRotate270(int target[SIZE][SIZE], int source[SIZE][SIZE], int size);

Поворот матрицы на 270 градусов по часовой стрелке.
*/
