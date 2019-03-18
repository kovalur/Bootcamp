#include <stdio.h>

#define SIZE 3

void matrixPrint(FILE *out, int matrix[SIZE][SIZE], int size) {
    int last = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < last; col++ ) {
            fprintf(out, "%d ", matrix[col][row]);
        }
        fprintf(out, "%d\n", matrix[last][row]);
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

int main() {
    FILE *out = fopen("tast.out", "w");
    int size = SIZE;
    int matrix[size][size];
    
    matrixFillWithEvenNaturalNumbers(matrix, size);
    matrixPrint(out, matrix, size);
    fclose(out);
    
    return 0;
}
