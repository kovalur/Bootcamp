#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = 1, counter = 0; row <= total; row++ ) {
        for ( int col = 1; col < row; col++ ) {
            counter += 1;
            printf("%d ", counter);
        }
        counter += 1;
        printf("%d\n", counter);
    }
    
    return 0;
}
