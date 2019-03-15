#include <stdio.h>

#define MAX_LENGTH 100

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = 0;
    
    for ( int x; len < MAX_LENGTH && fscanf(in, "%d", &x) == 1; len++ );
    fclose(in);

    fprintf(out, "%d\n", len);
    fclose(out);
    
    return 0;
}
