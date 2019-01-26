#include <stdio.h>

void arrayShiftLeft(int array[], int size) {
    for ( int i = 1, j = i - 1; i < size; i++, j++ ) {
        int tmp = array[j];

        array[j] = array[i];
        array[i] = tmp;
    }
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int last = size - 1;

    arrayShiftLeft(array, size);

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);

    return 0;
}
