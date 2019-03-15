#include <stdio.h>

void strUpperCase(char str[]) {
    for ( int i = 0, ch = str[i]; ch != '\0'; i++, ch = str[i] ) {
        if ( ch >= 'a' && ch <= 'z' ) {
            str[i] = ch - 32;
        }
    }
}

int main() {
    char str[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    
    strUpperCase(str);
    
    printf("%s\n", str);
    
    return 0;
}
