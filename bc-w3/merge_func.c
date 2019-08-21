#include <stdio.h>

#define SIZE 9

void merge(int array[], int lo, int mid, int hi) {
    int size = hi - lo;
    int buffer[size];
    
    for ( int i = 0, j = lo, k = mid; i < size; i++ ) {
        if ( j < mid && k < hi ) {
            int a = array[j];
            int b = array[k];

            if ( a < b ) {
                buffer[i] = a;
                j += 1;
            } else {
                buffer[i] = b;
                k += 1;
            }
        } else if ( j < mid ) {
            buffer[i] = array[j];
            j += 1;
        } else if ( k < hi ) {
            buffer[i] = array[k];
            k += 1;
        }
    }
    
    for ( int i = 0, j = lo; i < size; i++, j++ ) {
        array[j] = buffer[i];
    }
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

int main() {
    int array[] = {1, 2, 3, 4, 5, 1, 2, 3, 4};
    int lo = 3;
    int mid = 5;
    int hi = 8;

    printArray(array, SIZE);

    merge(array, lo, mid, hi);

    printf("\n");
    printArray(array, SIZE);

    return 0;
}
