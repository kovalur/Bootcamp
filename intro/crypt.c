#include <stdio.h>

int main() {
    int plain1, encrypted1;
    int plain2, encrypted2;
    int length;
    int keyA, keyB;
    int plain, encrypted;
    
    scanf("%d %d", &plain1, &encrypted1);
    scanf("%d %d", &plain2, &encrypted2);
    scanf("%d", &length);
    
    keyB = (plain1 * encrypted2 - encrypted1 * plain2) / (plain1 - plain2);
    keyA = (encrypted2 - keyB) / plain2;
    
    for ( ; length > 0; length-- ) {
        scanf("%d", &encrypted);
        plain = (encrypted - keyB) / keyA;
        if ( length > 1 ) {
            printf("%d ", plain);
        }
    }
    printf("%d\n", plain);
    
    return 0;
}
