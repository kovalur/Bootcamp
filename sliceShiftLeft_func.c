#include <stdio.h>

void sliceShiftLeft(int array[], int start, int end) {
    for ( ; start < end; start++ ) {
        int temp = array[start+1];
        
        array[start+1] = array[start];
        array[start] = temp;
    }
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int start = 3;
    int end = 7;
    int last = size - 1;
    
    sliceShiftLeft(array, start, end);
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
    return 0;
}
