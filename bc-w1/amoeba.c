#include <stdio.h>

int main() {
    int hours, monad;
    
    scanf("%d %d", &monad, &hours);
    
    for ( int hour = 1; hour <= hours; hour++ ) {
        monad *= 2;
        printf("%dh => %d amoeba(s)\n", hour, monad);
    }
    
    return 0;
}
