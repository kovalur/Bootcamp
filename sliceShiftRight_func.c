#include <stdio.h>

// void sliceShiftRight(int array[], int start, int end) {
//     for ( int prev = end - 1; end > start; end--, prev-- ) {
//         int tmp = array[prev];
        
//         array[prev] = array[end];
//         array[end] = tmp;
//     }
// }


void sliceShiftRight(int array[], int start, int end) {
    int tmp = array[start];
    
    for ( ; start < end; start++, tmp = array[start] ) {
        array[start] = tmp;

    }
    array[start] = tmp;
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int start = 3;
    int end = 7;
    int last = size - 1;
    
    sliceShiftRight(array, start, end);
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
    return 0;
}
