#include <stdio.h>

#define SIZE 26

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int occurrences[SIZE];
    
    for ( int i = 0; i < SIZE; i++ ) {
        occurrences[i] = 0;
    }
    
    for ( char letter; fscanf(in, "%c", &letter) == 1; ) {
        if ( letter >= 'A' && letter <= 'Z' ) {
            letter += 32;
        }
        if ( letter >= 'a' && letter <= 'z' ) {
            occurrences[letter-97] += 1;
        }
    }
    fclose(in);
    
    for ( int i = 0; i < SIZE; i++ ) {
        char letter = i + 97;
        int count = occurrences[i];
        
        if ( count != 0 ) {
            fprintf(out, "%c %d\n", letter, count);
        }
    }
    fclose(out);
    
    return 0;
}
