#include <stdio.h>

void strUpperCase(char str[]) {
    const int shift = 'a' - 'A';
    
    for ( int i = 0, ch = str[i]; ch != '\0'; i++, ch = str[i] ) {
        if ( ch >= 'a' && ch <= 'z' ) {
            str[i] = ch - shift;
        }
    }
}

int main() {
    int size = 6;
    char str[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    
    strUpperCase(str);
    
    for ( int i = 0; i < size; i++ ) {
        printf("%c", str[i]);
    } 
    printf("\n");
    
    return 0;
}
