#include <stdio.h>

#define SIZE 3

void matrixMultiply(int matrix[SIZE][SIZE], int size, int multiplier) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            matrix[i][j] *= multiplier;
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
    int multiplier;
    int size = SIZE;
    int matrix[size][size];
    
    scanf("%d", &multiplier);
    
    matrixFillWithEvenNaturalNumbers(matrix, size);
    matrixPrint(matrix, size);
    printf("-----------------------------------\n");
    matrixMultiply(matrix, size, multiplier);
    matrixPrint(matrix, size);
    
    return 0;
}

/*
Задача matrixMultiply()

Условие задачи
void matrixMultiply(int matrix[SIZE][SIZE], int size, int multiplier)
*/
