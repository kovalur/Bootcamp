#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 100;
    char str[size];
    int len = 0;
    int last;
    
    for ( ; len < size && fscanf(in, "%c", &str[len]) == 1; len++ );
    fclose(in);
    
    last = len - 1;
    for ( int i = 0, j = last; i < j; i++, j-- ) {
        int temp = str[j];
        
        str[j] = str[i];
        str[i] = temp;
    }
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%c", str[i]);
    }
    fprintf(out, "%c\n", str[last]);
    fclose(out);
    
    return 0;
}
