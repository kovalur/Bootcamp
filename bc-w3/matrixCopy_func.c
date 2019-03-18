#include <stdio.h>

#define SIZE 3

void matrixCopy(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            target[row][col] = source[row][col];
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
    matrixCopy(target, source, size);
    matrixPrint(target, size);
    
    return 0;
}
