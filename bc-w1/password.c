#include <stdio.h>

int main() {
    for ( int attemptsLeft = 5; attemptsLeft >= 0; ) {
        int password;
        
        scanf("%d", &password);
        
        if ( attemptsLeft == 0 ) {
            printf("denied\n");
            return 0;
        } else if ( password == 1488 ) {
            printf("accepted\n");
            return 0;
        } else {
            printf("incorrect password\n");
            attemptsLeft -= 1;
        }
    }
    
    return 0;
}
