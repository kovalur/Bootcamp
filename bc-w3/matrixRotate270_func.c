#include <stdio.h>

#define SIZE 3

void matrixRotate270(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0, cot = size - 1; col < size; col++, cot-- ) {
            target[row][col] = source[cot][row];
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

void matrixFillWithNaturalNumbers(int matrix[SIZE][SIZE], int size) {
    for ( int counter = 1, i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            matrix[i][j] = counter;
            counter += 1;
        }
    }
}

int main() {
    int size = SIZE;
    int target[size][size];
    int source[size][size];
    
    matrixFillWithNaturalNumbers(source, size);
    matrixPrint(source, size);
    matrixRotate270(target, source, size);
    printf("------------------------------\n");
    matrixPrint(target, size);
    
    return 0;
}
