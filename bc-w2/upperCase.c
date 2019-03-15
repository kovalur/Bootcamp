#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    for ( char letter; fscanf(in, "%c", &letter) == 1; ) {
        if ( letter >= 'a' && letter <= 'z' ) {
            letter = letter - 32;
        }
        fprintf(out, "%c", letter);
    }
    fclose(in);
    fprintf(out, "\n");
    fclose(out);
    
    return 0;
}
