#include <stdio.h>

int main() {
    int length;
    
    scanf("%d", &length);
    
    for ( int number; length > 0; length-- ) {
        scanf("%d", &number);
        printf("%d\n", number^42);
    }
    
    return 0;
}
