#include <stdio.h>

void arrayExchange(int array[], int len) {
    for ( int i = 1, j = 0; i < len; i += 2, j += 2 ) {
        int temp = array[j];

        array[j] = array[i];
        array[i] = temp;
    }
}

int main() {
    int len = 11;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, '\0'};
    int last = len - 1;
    
    arrayExchange(array, len);

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);

    return 0;
}
