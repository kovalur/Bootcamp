#include <stdio.h>

void arraySort(int array[], int size) {
    const int last = size - 1;

    for ( int sorted = 0; sorted == 0; ) {
        sorted = 1;
        for ( int i = 1; i < size; i++ ) {
            int j = i - 1;
            int current = array[i];
            int previous = array[j];

            if ( i == last && sorted != 0 ) {
                sorted = 1;
            }

            if ( previous > current ) {
                array[i] = previous;
                array[j] = current;
                if ( i != last ) {
                    sorted = 0;
                }
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
