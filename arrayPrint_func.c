#include <stdio.h>

#define MAX_SIZE 100

void arrayPrint(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int main() {
    int size = 0;
    int array[MAX_SIZE];
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    for ( ; size < MAX_SIZE && fscanf(in, "%d", &array[size]) == 1; size++ );
    
    arrayPrint(out, array, size);
    fclose(in);
    fclose(out);
    
    return 0;
}
