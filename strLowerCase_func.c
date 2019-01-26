#include <stdio.h>

void strLowerCase(char str[]) {
    const int shift = 'a' - 'A';
    
    for ( int i = 0, ch = str[i]; ch != '\0'; i++, ch = str[i] ) {
        if ( ch >= 'A' && ch <= 'Z' ) {
            str[i] = ch + shift;
        }
    }
}

int main() {
    char str[] = {'H', 'E', 'L', 'L', 'O', '!', '\0'};
    
    strLowerCase(str);
    
    for ( int i = 0; str[i] != '\0'; i++ ) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}
