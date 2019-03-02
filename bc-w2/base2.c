#include <stdio.h>

int main() {
    int number, base;
    int power = 1;
    int ch;
    
    scanf("%d %d", &number, &base);
    
    if ( number < 0 ) {
        number = -number;
        printf("-");
    }
    
    for ( int tmp = number / base; power <= tmp; power *= base );
    
    for ( ; power >= base; power /= base ) {
        ch = number / power + 48;
        if ( ch > 57 ) {
            ch += 7;
        }
        printf("%c", ch);
        number %= power;
    }
    ch = number / power + 48;
    if ( ch > 57 ) {
        ch += 7;
    }
    printf("%c\n", ch);
    
    return 0;
}
