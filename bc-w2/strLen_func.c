#include <stdio.h>

int strLen(char str[]) {
    int len = 0;
    
    for ( ; str[len] != '\0'; len++ );
    return len;
}

int main() {
    char str[] = {'h', 'e', 'l', 'l', 'o', '!', '\0'};
    int len = 0;
    
    len = strLen(str);
    
    printf("%d\n", len);
    
    return 0;
}

/*
Задача strLen()

Условие задачи
int strLen(char str[])

Подсчитать длину заданной строки.
*/
