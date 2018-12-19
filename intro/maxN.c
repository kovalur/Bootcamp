#include <stdio.h>

int main() {
    int length, max;
    
    scanf("%d", &length);
    int array[length];
    
    for ( int i = 0; i < length; i++  ) {
        scanf("%d", &array[i]);
        if ( array[i] > array[i-1] ) {
            max = array[i];
        }
    }
    
    printf("%d\n", max);
}
