#include <stdio.h>

int main() {
    int x, y;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%d %d", &x, &y);
    fclose(in);
    
    fprintf(out, "%d&%d=%d\n", x, y, x&y);
    fprintf(out, "%d|%d=%d\n", x, y, x|y);
    fprintf(out, "%d^%d=%d\n", x, y, x^y);
    fprintf(out, "%d<<%d=%d\n", x, y, x<<y);
    fprintf(out, "%d>>%d=%d\n", x, y, x>>y);
    fclose(out);
    
    return 0;
}
