#include <stdio.h>

int main() {
    int phoneNumber, callDuration;
    
    scanf("%d %d", &phoneNumber, &callDuration);
    
    if ( phoneNumber == 101 || phoneNumber == 102 || phoneNumber == 103 || phoneNumber == 104 || phoneNumber == 112 ) {
        printf("%d$\n", 0);
    } else if ( phoneNumber >= 1000000 && phoneNumber <= 9999999 ) {
        printf("%d$\n", 1*callDuration);
    } else if ( phoneNumber >= 100 && phoneNumber <= 999 ) {
        printf("%d$\n", 40*callDuration);
    } else {
        printf("%d\n", -1);
    }
    
    return 0;
}
