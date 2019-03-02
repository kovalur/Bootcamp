#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    if ( size == 0 ) {
        return 0;
    }
    
    for ( int counter = 1; counter / size < size; counter++ ) {
        for ( ; counter % size > 0; counter++ ) {
            printf("%d ", counter);
        }
        printf("%d\n", counter);
    }
    
    return 0;
}
