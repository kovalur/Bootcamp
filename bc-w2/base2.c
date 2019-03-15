#include <stdio.h>

int main() {
    int number, base, ch;
    int power = 1;
    
    scanf("%d %d", &number, &base);
    
    if ( number < 0 ) {
        number = -number;
        printf("-");
    }
    
    for ( int temp = number / base; power <= temp; power *= base );
    
    for ( ; power >= base; power /= base ) {
        ch = number / power + 48;
        if ( ch > '9' ) {
            ch += 7;
        }
        printf("%c", ch);
        number %= power;
    }
    ch = number / power + 48;
    if ( ch > '9' ) {
        ch += 7;
    }
    printf("%c\n", ch);
    
    return 0;
}
