#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int row = 1, counter = size * size; row <= size; row++ ) {
        counter -= (size - 1);
        for ( int col = 1; col < size; col++ ) {
            printf("%d ", counter);
            counter += 1;
        }
        printf("%d\n", counter);
        counter -= size;
    }
    
    return 0;
}
