#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 101;
    char str1[size];
    char str2[size];
    int len1 = 0;
    int len2 = 0;
    
    fscanf(in, "%100s %100s", str1, str2);
    fclose(in);
    for ( ; str1[len1] != '\0'; len1++ );
    for ( ; str2[len2] != '\0'; len2++ );
    if ( len1 != len2 ) {
        fprintf(out, "no\n");
    } else {
        for ( int i = 0; i < len1; i++ ) {
            if ( str1[i] != str2[i] ) {
                fprintf(out, "no\n");
                fclose(out);
                return 0;
            }
        }
        fprintf(out, "yes\n");
    }
    fclose(out);
    
    return 0;
}
