#include <stdio.h>

#define MAX_SIZE 100

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 0;
    
    for ( int x; size < MAX_SIZE && fscanf(in, "%d", &x) == 1; size++ );
    fclose(in);
    fprintf(out, "%d\n", size);
    fclose(out);
    return 0;
}
