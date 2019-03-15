#include <stdio.h>

int main() {
    int length, number;
    
    scanf("%d", &length);
    
    for ( ; length > 0; length-- ) {
        scanf("%d", &number);
        printf("%d\n", number^42);
    }
    
    return 0;
}
