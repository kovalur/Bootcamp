#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char temp;
    int swaps = 0;
    int zeros = 0;
    
    for ( ; fscanf(in, "%c", &temp) != EOF; ) {
        if ( temp == '0' ) {
            zeros += 1;
        }
    }
    
    rewind(in);
    for ( int i = 0; fscanf(in, "%c", &temp) != EOF && i < zeros; i++ ) {
        if ( temp == '1' ) {
            swaps += 1;
        }
    }
    fclose(in);

    fprintf(out, "%d\n", swaps);
    fclose(out);

    return 0;
}
