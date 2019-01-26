#include <stdio.h>

void arrayShiftLeft(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; ) {
        int tmp = array[i];
        
        i += 1;
        array[i-1] = array[i];
        array[i] = tmp;
    }
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int last = size - 1;
    
    arrayShiftLeft(array, size);
    //arrayShiftLeft(array, size);
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
    return 0;
}
