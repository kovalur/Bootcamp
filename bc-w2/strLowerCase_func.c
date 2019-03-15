#include <stdio.h>

void strLowerCase(char str[]) {
    for ( int i = 0, ch = str[i]; ch != '\0'; i++, ch = str[i] ) {
        if ( ch >= 'A' && ch <= 'Z' ) {
            str[i] = ch + 32;
        }
    }
}

int main() {
    char str[] = {'H', 'E', 'L', 'L', 'O', '!', '\0'};
    
    strLowerCase(str);
    
    printf("%s\n", str);
    
    return 0;
}
