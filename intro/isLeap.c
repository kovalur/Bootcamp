#include <stdio.h>

int main() {
    int numberOfdays;
    
    scanf("%d", &numberOfdays);
    
    if ( numberOfdays == 366 ) {
        printf("yes\n");
    } else if ( numberOfdays == 365 ) {
        printf("no\n");
    } else {
        printf("Invalid param\n");
    }
    
    return 0;
}
