#include <stdio.h>

int main() {
    int value;
    int len = 10;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    for ( ; fscanf(in, "%d", &value) == 1 && len > 1; len-- ) {
        fprintf(out, "%d ", value);
    }
    fclose(in);
    fprintf(out, "%d\n", value);
    fclose(out);
    
    return 0;
}
