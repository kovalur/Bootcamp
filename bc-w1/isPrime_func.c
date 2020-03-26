#include <stdio.h>

// int isPrime(int n) {
//     int check = 1;
    
//     if ( n <= 1 ) {
//         check = 0;
//     } else {
//         for ( int i = 2; i < n; i++ ) {
//             if ( n % i == 0 ) {
//                 check = 0;
//                 i = n;
//             }
//         }
//     }
    
//     return check;
// }

// Better solution
int isPrime(int n) {
    int halfOfN = n / 2;
    
    if ( n <= 1 ) {
        return 0;
    }
    
    for ( int i = 2; i <= halfOfN; i++ ) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    
    return 1;
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
