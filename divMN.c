#include <stdio.h>

int main() {
    int min, max, m, n;
    int gcd, lcm, multiple, minMultiple;
    
    scanf("%d %d %d %d", &min, &max, &m, &n);
    
    multiple = m * n;
    for ( ; m > 0 && n > 0; ) {
        m = m % n;
        if ( m != 0 ) {
            n = n % m;
        }
        if ( m == 0 ) {
            gcd = n;
        } else if ( n == 0 ) {
            gcd = m;
        }
    }
    lcm = multiple / gcd;
    
    minMultiple = min - min % lcm;
    if ( minMultiple < min ) {
        minMultiple += lcm;
    }
    
    for ( ; minMultiple <= max; minMultiple += lcm ) {
        printf("%d\n", minMultiple);
    }
    
    return 0;
}
