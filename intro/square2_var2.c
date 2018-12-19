#include <stdio.h>

int main() {
    int size;
    int counter = 1;
    
    scanf("%d", &size);
    
    for ( int i = 1; i <= size; i++ ) {
        for ( ; counter <= size * i - 1; ) {
            printf("%d ", counter);
            counter += 1;
        }        
        printf("%d\n", counter);
        counter += 1;
    }
    
    return 0;
}

    // for ( int i = 1, counter = 1; i <= size; i++, counter++ ) {
    //     for ( ; counter <= size * i - 1; counter++ ) {
    //         printf("%d ", counter);
    //     }
    //     printf("%d\n", counter);
    // }
