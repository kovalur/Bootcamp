#include <stdio.h>

#define SIZE 11

void bubbleSort(int array[], int size) {
    int counter = 0;
    
    for ( int i = 1; i < size; i++ ) {
        int isSorted = 1;
        
        for ( int i = 0, j = 1; j < size; i++, j++ ) {
            if ( array[j] < array[i] ) {
                int temp = array[i];
                
                array[i] = array[j];
                array[j] = temp;
                isSorted = 0;
            }
            counter++;
        }
        if ( isSorted ) {
            return;
        }
    }
        printf("%d", counter);
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

int main () {
    int size = SIZE;
    //int array[SIZE] = {24, 1, 0, 15, 23, 8, 18, 345, 6, 15, 0};
    int array[SIZE] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printArray(array, size);
    printf("\n######################################\n");
    bubbleSort(array, size);
    printArray(array, size);
    
    return 0;
}
