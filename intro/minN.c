#include <stdio.h>

int main() {
    int length;
    int current;
    int min = 0;
    
    scanf("%d", &length);
    
    for ( int i = 1; i <= length; i++  ) {
        scanf("%d", &current);
        if ( i == 1 || current < min ) {
            min = current;
        }
    }
    
    printf("%d\n", min);
    
    return 0;
}
