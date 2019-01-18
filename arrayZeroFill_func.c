#include <stdio.h>

void arrayZeroFill(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        array[i] = 0;
    }
}

int main() {
    int size = 100;
    int array[size];
    
    arrayZeroFill(array, size);
    
    return 0;
}
