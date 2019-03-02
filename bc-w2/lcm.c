#include <stdio.h>

int main() {
    unsigned long long x, y;
    unsigned long long gcd, multiple;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%llu %llu", &x, &y);
    fclose(in);
    
    multiple = x * y;
    for ( ; x > 0 && y > 0; ) {
        x = x % y;
        if ( x != 0 ) {
            y = y % x;
        }
        if ( x == 0 ) {
            gcd = y;
        } else if ( y == 0 ) {
            gcd = x;
        }
    }
    
    fprintf(out, "%llu\n", multiple/gcd);
    fclose(out);
    
    return 0;
}
