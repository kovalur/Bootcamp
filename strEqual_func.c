#include <stdio.h>

int strEqual(char str1[], char str2[]) {
    int len1 = 0;
    int len2 = 0;
    
    for ( ; str1[len1] != '\0'; len1++ );
    for ( ; str2[len2] != '\0'; len2++ );
    
    if ( len1 != len2 ) {
        return 0;
    } else {
        for ( int i = 0; i < len1; i++ ) {
            if ( str1[i] != str2[i] ) {
                return 0;
            }
        }
    }
    
    return 1;
}

int main() {
    char str1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str2[] = {'h', 'e', 'l', 'l', 'o', 'g', '\0'};
    int isStringsEqual;
    
    isStringsEqual = strEqual(str1, str2);
    
    printf("%d\n", isStringsEqual);
    
    return 0;
}
