#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 100;
    char str[size];
    
    fscanf(in, "%100s", str);
    fclose(in);
    
    for ( int i = 0, ch = str[i]; ch != '\0'; i++, ch = str[i] ) {
        const int shift = 13;
        
        if ( ch >= 'a' && ch <= 'm' ) {
            str[i] = ch + shift;
        } else if ( ch > 'm' && ch <= 'z' ) {
            str[i] = ch - shift;
        } else if ( ch >= 'A' && ch <= 'M' ) {
            str[i] = ch + shift;
        } else if ( ch > 'M' && ch <= 'Z' ) {
            str[i] = ch - shift;
        }
        fprintf(out, "%c", str[i]);
    }
    fprintf(out, "\n");
    fclose(out);
    
    return 0;
}
