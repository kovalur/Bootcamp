#include <stdio.h>

#define MULTIPLE 5

int main() {
    int max;
    
    scanf("%d", &max);
    
    max = max - max % MULTIPLE;
    
    for ( int i = 0; i < max; i += MULTIPLE ) {
        printf("%d ", i);
    }
    
    printf("%d\n", max);
}
