#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    for ( char tmp; fscanf(in, "%c", &tmp) == 1; ) {
        if ( tmp >= 'A' && tmp <= 'Z' ) {
            tmp = tmp + 32;
        }
        fprintf(out, "%c", tmp);
    }
    fclose(in);
    fprintf(out, "\n");
    fclose(out);
    
    return 0;
}
