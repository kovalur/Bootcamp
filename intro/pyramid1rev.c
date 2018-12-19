#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = 0; row < total; row++ ) {
        for ( int col = 1; col < total - row; col++ ) {
            printf("%d ", col);
        }
        printf("%d\n", total-row);
    }
    
    return 0;
}
