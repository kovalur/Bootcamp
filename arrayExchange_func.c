#include <stdio.h>

void arrayExchange(int array[], int len) {
    for ( int i = 1; i < len; i++ ) {
        int prev = i - 1;
        int tmp = array[prev];
        
        if ( tmp % 2 == 0 && array[i] % 2 != 0 ) {
            array[prev] = array[i];
            array[i] = tmp;
        }
    }
}

int main() {
    int size = 11;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int last = size - 1;
    int len = 11;
    
    arrayExchange(array, len);
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
    return 0;
}
