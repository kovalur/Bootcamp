#include <stdio.h>

void arrayIncrement(int array[], int size, int increment) {
    for ( int i = 0; i < size; i++ ) {
        array[i] += increment;
    }
}

int main() {
    int size = 100;
    int increment = 1;
    int array[size];
    
    for ( int i = 0; i < size; i++ ) {
        array[i] = i;
    }
    
    arrayIncrement(array, size, increment);
    
    return 0;
}
