#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 100;
    int array[size];
    int len, last;
    
    fscanf(in, "%d", &len);
    
    last = len - 1;
    for ( int i = 0; i < len && fscanf(in, "%d", &array[i]) == 1; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
        if ( i != last ) {
            fprintf(out, "%d ", array[i]);
        }
    }
    fclose(in);
    fprintf(out, "%d\n", array[last]);
    fclose(out);
    
    return 0;
}
