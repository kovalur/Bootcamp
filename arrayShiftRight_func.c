#include <stdio.h>

void arrayShiftRight(int array[], int size) {
    int last = size - 1;
    int temp = array[last];
    
    for ( int i = last; i > 0; i-- ) {
        array[i] = array[i-1];
    }
    array[0] = temp;
}

int main () {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int last = size - 1;

    arrayShiftRight(array, size);

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);

    return 0;
}
