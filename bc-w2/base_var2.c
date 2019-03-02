#include <stdio.h>

int main() {
    int number, base;
    FILE *out = fopen("task.out", "w");
    
    scanf("%d %d", &number, &base);
    
    for ( int temp = number / base; temp != 0; temp = number / base) {
        fprintf(out, "%d ", number-temp*base);
        number = temp * base;
    }
    fclose(out);
    
    return 0;
}
