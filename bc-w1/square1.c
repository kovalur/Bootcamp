#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int col = 1; col <= size; col++ ) {
    	for ( int row = 1; row < size; row++ ) {
    		printf("%d ", row);
    	}
        printf("%d\n", size);
    }
    
    return 0;
}
