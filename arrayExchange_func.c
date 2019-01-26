#include <stdio.h>

void arrayExchange(int array[], int len) {
    for ( int i = 1, j = i - 1; i < len; i += 2, j += 2 ) {
        int tmp = array[j];
        
        if ( tmp % 2 == 0 && array[i] % 2 != 0 ) {
            array[j] = array[i];
            array[i] = tmp;
        } else if ( tmp % 2 != 0 && array[i] % 2 == 0 ) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
}

int main() {
    int len = 0;
    //int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, '\0'};
    int array[] = {'\0'};
    int last = len - 1;

    arrayExchange(array, len);

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);

    return 0;
}
