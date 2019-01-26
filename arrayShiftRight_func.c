#include <stdio.h>

void arrayShiftRight(int array[], int size) {
    for ( int i = size - 1, j = i - 1; i > 0; i--, j-- ) {
        int temp = array[j];

        array[j] = array[i];
        array[i] = temp;
    }
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
