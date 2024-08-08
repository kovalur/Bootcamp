#include <stdio.h>

#define SIZE 3

void matrixIncrement(int matrix[SIZE][SIZE], int increment[SIZE][SIZE], int size) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            matrix[i][j] += increment[i][j];
        }
    }
}

void matrixFillWithEvenNaturalNumbers(int matrix[SIZE][SIZE], int size) {
    for ( int row = 0, counter = 2; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            matrix[row][col] = counter;
            counter += 2;
        }
    }
}

void matrixFillWithOnes(int matrix[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            matrix[row][col] = 1;
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
    int matrix[size][size];
    int increment[size][size];
    
    matrixFillWithEvenNaturalNumbers(matrix, size);
    matrixPrint(matrix, size);
    printf("----------------------------------\n");
    matrixFillWithOnes(increment, size);
    matrixPrint(increment, size);
    printf("----------------------------------\n");    
    matrixIncrement(matrix, increment, size);
    matrixPrint(matrix, size);
    
    return 0;
}

/*
Задача matrixIncrement()

Условие задачи
void matrixIncrement(int matrix[SIZE][SIZE], int increment[SIZE][SIZE],
int size)
*/
