#include <stdio.h>

int main() {
    int total;
    int rows, cols;
    
    scanf("%d %d %d", &total, &rows, &cols);
    
    if ( rows < cols ) {
        rows = cols;
    }
    
    for ( int row = rows + 1; row <= total; row++ ) {
        for ( int col = cols + 1; col < row; col++ ) {
            printf("%d ", col);
        }
        printf("%d\n", row);
    }
    
    return 0;
}


// 5 3 2 //

// 1_
// 1_   2|
// 1_   2|_  3_
// 1    2|   3   4
// 1    2|   3   4   5

// 3   4
// 3   4   5


// 5 2 3 //

// 1_
// 1_   2_
// 1    2   3|
// 1    2   3|   4
// 1    2   3|   4   5

// 4
// 4   5
