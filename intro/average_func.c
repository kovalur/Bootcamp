#include <stdio.h>

unsigned int average(unsigned int a, unsigned int b) {
    return a / 2 + b / 2 + (a % 2 + b % 2) / 2;
}
    
int main() {
    unsigned int a = 3000000001;
    unsigned int b = 3000000002;
    
    printf("%u\n", average(a, b));
    
    return 0;
}
