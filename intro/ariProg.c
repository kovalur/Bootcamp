#include <stdio.h>

int main() {
    int start, step, quantity;
    int current = 0;
    
    scanf("%d %d %d", &start, &step, &quantity);
    
    current = start;
    for ( ; quantity > 1; quantity-- ) {
        printf("%d_", current);
        current += step;
    }
    printf("%d\n", current);
    
    return 0;
}
