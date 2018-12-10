#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int col = 1; col <= total; col++ ) {
        for ( int row = 1; row < col; row++ ) {
            printf("%d ", row);
        }
        printf("%d\n", col);
    }
    
    return 0;
}
