#include <stdio.h>

void strCopy(char target[], char source[]) {
    int counter = 0;
    
    for ( ; source[counter] != '\0'; counter++ ) {
        target[counter] = source[counter];
    }
    target[counter] = '\0';
}

int main() {
    int size = 15;
    char source[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', '\0'};
    char target[] = {'k', 'l', 'm', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    int last = size - 1;
    
    strCopy(target, source);
    
    for ( int i = 0; i < last && target[i] != '\0'; i++ ) {
        printf("%c", target[i]);
    }
    printf("\n");
    
    return 0;
}
