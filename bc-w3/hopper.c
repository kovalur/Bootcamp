#include <stdio.h>

#define SIZE 101

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int maxJump, cell;
    unsigned long long ways[SIZE];
    
    fscanf(in, "%d %d", &maxJump, &cell);
    fclose(in);
    
    if ( maxJump > cell ) {
        maxJump = cell;
    }
    
    for ( int i = 0; i < maxJump; i++ ) {
        ways[i] = 1 << i;
    }
    
    ways[maxJump] = ways[maxJump-1] * 2 - 1;
    for ( int i = maxJump + 1, j = 0; i < cell; i++, j++ ) {
        ways[i] = ways[i-1] * 2 - ways[j];
    }
    
    fprintf(out, "%llu\n", ways[cell-1]);
    fclose(out);
    
    return 0;
}
