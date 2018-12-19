#include <stdio.h>

int main() {
    int position;
    int prime = 2;
    
    scanf("%d", &position);
    
    if ( position <= 0 ) {
        printf("-1\n");
    } else {
        for ( int i = 2, counter = 1; counter <= position; i++ ) {
            for ( int j = 2; j <= i; j++ ) {
                if ( j == i ) {
                    counter += 1;
                }
                if ( i % j == 0 ) {
                    j = i + 1;
                }
                if ( counter == position ) {
                    prime = i;
                }
            }
        }
        printf("%d\n", prime);
    }
    
    return 0;
}

// 2 3 5 7 11
// 1 2 3 4 5
