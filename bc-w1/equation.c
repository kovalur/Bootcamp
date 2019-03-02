#include <stdio.h>

int main() {
    int discriminant;
    
    scanf("%d", &discriminant);
    
    if ( discriminant < 0 ) {
        printf("%d\n", 0);
    } else if ( discriminant == 0 ) {
        printf("%d\n", 1);
    } else {
        printf("%d\n", 2);
    }
    
    return 0;
}
