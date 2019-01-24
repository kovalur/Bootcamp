#include <stdio.h>

int main() {
    int size = 100;
    int array[size];
    int len = 0;
    int needle;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%d", &needle);
    
    for ( int i = 0; i < size && fscanf(in, "%d", &array[i]) == 1; i++ ) {
        len += 1;
    }
    
    for ( int i = 0; i < len; i++ ) {
        if ( array[i] == needle ) {
            fprintf(out, "%d\n", i);
            fclose(in);
            fclose(out);
            
            return 0;
        }
    }
    fprintf(out, "-1\n");
    fclose(in);
    fclose(out);
    
    return 0;
}
