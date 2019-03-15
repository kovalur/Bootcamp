#include <stdio.h>

#define MAX_SIZE 101

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char array[MAX_SIZE];
    int len = 0;
    
    fscanf(in, "%100s", array);
    fclose(in);
    
    for ( ; array[len] != '\0'; len++ );
    
    fprintf(out, "%d\n", len);
    fclose(out);
    
    return 0;
}
