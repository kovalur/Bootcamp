#include <stdio.h>

void arraySort(int array[], int size) {
    const int last = size - 1;
    
    for ( int isSorted = 1; isSorted == 0; isSorted = 1 ) {
        for ( int i = 1; i < size; i++ ) {
            int j = i - 1;
            int curr = array[i];
            int prev = array[j];
    
            if ( prev > curr ) {
                array[i] = prev;
                array[j] = curr;
                isSorted = 0;
                printf("{%d->%d}\n", array[i], array[j]);
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
