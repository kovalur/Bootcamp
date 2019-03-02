#include <stdio.h>

int isPrime(int n) {
    int check = 1;
    
    if ( n <= 1 ) {
        check = 0;
    } else {
        for ( int i = 2; i < n; i++ ) {
            if ( n % i == 0 ) {
                check = 0;
                i = n;
            }
        }
    }
    
    return check;
}

int main() {
    int number;
    
    scanf("%d", &number);
    
    if ( isPrime(number) ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
