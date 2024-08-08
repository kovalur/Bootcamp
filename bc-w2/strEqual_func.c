#include <stdio.h>

int strEqual(char str1[], char str2[]) {
    for ( int i = 0; str1[i] == str2[i]; i++ ) {
        if ( str1[i] == '\0' ) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str2[] = {'h', 'e', 'l', 'l', 'o', 'g', '\0'};
    int isStringsEqual;

    isStringsEqual = strEqual(str1, str2);

    printf("%d\n", isStringsEqual);

    return 0;
}

/*
Задача strEqual()

Условие задачи
int strEqual(char str1[], char str2[])

Выяснить, равны ли строки.
*/
