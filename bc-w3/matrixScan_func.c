#include <stdio.h>

#define SIZE 3

void matrixScan(FILE *in, int matrix[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            fscanf(in, "%d", &matrix[col][row]);
        }
    }
}

void matrixPrintToScreen(int matrix[SIZE][SIZE], int size) {
    int last = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < last; col++ ) {
            printf("%d ", matrix[row][col]);
        }
        printf("%d\n", matrix[row][last]);
    }
}

void printMatrixFromFileToScreen(FILE *file, int size) {
    int last = size - 1;
    
    for ( int row = 0, temp; row < size; row++ ) {
        for ( int col = 0; col < last; col++ ) {
            fscanf(file, "%d", &temp);
            printf("%d ", temp);
        }
        fscanf(file, "%d", &temp);
        printf("%d\n", temp);
    }
    
}

void printToFileMatrixOfOddNaturalNumbers(FILE *file, int size) {
    int last = size - 1;
    
    for ( int row = 0, counter = 1; row < size; row++ ) {
        for ( int col = 0; col < last; col++ ) {
            fprintf(file, "%d ", counter);
            counter += 2;
        }
        fprintf(file, "%d\n", counter);
    }
}

int main() {
    FILE *in = fopen("task.in", "w+");
    int size = SIZE;
    int matrix[SIZE][SIZE];
    
    printToFileMatrixOfOddNaturalNumbers(in, size);
    rewind(in);
    matrixScan(in, matrix, size);
    matrixPrintToScreen(matrix, size);
    printf("----------------------------------\n");
    rewind(in);
    printMatrixFromFileToScreen(in, size);
    fclose(in);
    
    return 0;
}
