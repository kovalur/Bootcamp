#include <stdio.h>

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

void arrayShift(int array[], int size, int shift) {
    int buffer[size];
    int limit;
    
    shift %= size;
    if ( shift < 0 ) {
        shift += size;
    }
    limit = size - shift;
    if ( shift < size / 2 ) {
        for ( int i = size - 1, j = shift - 1; j >= 0; i--, j-- ) {
            buffer[j] = array[i];
        }
        for ( int i = size - 1, j = limit - 1; i >= 0; i--, j-- ) {
            array[i] = array[j];
        }
        for ( int i = 0; i < shift; i++ ) {
            array[i] = buffer[i];
        }
    } else {
        for ( int i = 0; i < limit; i++ ) {
            buffer[i] = array[i];
        }
        for ( int i = limit, j = 0; i < size; i++, j++ ) {
            array[j] = array[i];
        }
        for ( int i = limit - 1, j = size - 1; i >= 0; i--, j-- ) {
            array[j] = buffer[i];
        }
    }
}

int main() {
    int size = 5;
    int shift = 2;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    printArray(arr, size);
    printf("\n######################################\n");
    arrayShift(arr, size, shift);
    printArray(arr, size);

    return 0;
}
