#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    unsigned long long a, b;
    unsigned long long lcm, gcd, multiple;
    
    fscanf(in, "%llu %llu", &a, &b);
    fclose(in);
    
    multiple = a * b;
    // First possible solution (without swapping), less iterations
    // for ( ; a > 0 && b > 0; ) {
    //     a %= b;
    //     if ( a != 0 ) {
    //         b %= a;
    //     }
    //     if ( a == 0 ) {
    //         gcd = b;
    //     } else if ( b == 0 ) {
    //         gcd = a;
    //     }
    // }
    for ( ; a > 0 && b > 0; ) {
        unsigned long long temp;
        
        a %= b;
        temp = a;
        a = b;
        b = temp;
        if ( a == 0 ) {
            gcd = b;
        } else if ( b == 0 ) {
            gcd = a;
        }
    }
    lcm = multiple / gcd;
    
    fprintf(out, "%llu\n", lcm);
    fclose(out);
    
    return 0;
}
