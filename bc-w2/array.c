#include <stdio.h>

#define MAX_LENGTH 10

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int number;
    
    for ( int i = 1; fscanf(in, "%d", &number) == 1 && i < MAX_LENGTH; i++ ) {
        fprintf(out, "%d ", number);
    }
    fclose(in);
    fprintf(out, "%d\n", number);
    fclose(out);
    
    return 0;
}
