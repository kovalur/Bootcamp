#include <stdio.h>

void strCopy(char target[], char source[]) {
    int counter = 0;
    
    for ( ; source[counter] != '\0'; counter++ ) {
        target[counter] = source[counter];
    }
    target[counter] = '\0';
}

int main() {
    char source[] = {'a', 'b', 'c', 'd', 'e',
                    'f', 'g', 'h', 'i', 'j', '\0'};
    char target[] = {'k', 'l', 'm', 'o', 'p', 'q', 'r', 's',
                    't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    
    strCopy(target, source);
    
    printf("%s\n", target);
    
    return 0;
}

/*
Задача strCopy()
Условие задачи
void strCopy(char target[], char source[])

Гарантируется, что строка target не короче строки source.
*/
