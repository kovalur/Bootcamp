#include <stdio.h>

#define MAX_SIZE 101

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char array[MAX_SIZE];
    int length = 0;
    
    fscanf(in, "%100s", array);
    fclose(in);
    
    for ( ; array[length] != '\0'; length++ );
    
    fprintf(out, "%d\n", length);
    fclose(out);
    
    return 0;
}
