#include <stdio.h>

void strRot13(char str[]) {
    const int shift = 13;
    
    for ( int i = 0, ch = str[i]; ch != '\0'; i++, ch = str[i] ) {
        if ( ch >= 'a' && ch <= 'm' ) {
            str[i] = ch + shift;
        } else if ( ch > 'm' && ch <= 'z' ) {
            str[i] = ch - shift;
        } else if ( ch >= 'A' && ch <= 'M' ) {
            str[i] = ch + shift;
        } else if ( ch > 'M' && ch <= 'Z' ) {
            str[i] = ch - shift;
        }
    }
}

int main() {
    char str[] = {'W', 'e', 'l', 'l', ' ', 'd', 'o', 'n', 'e', '!', '\0'};
    
    strRot13(str);
    
    printf("%s\n", str);
    
    return 0;
}

/*
Задача strRot13()

Условие задачи
Написать функцию:
void strRot13(char str[])

Зашифровать строку по алгоритму ROT13
*/
