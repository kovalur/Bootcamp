#include <stdio.h>

int intScan(FILE *in) {
    int number;
    
    fscanf(in, "%d", &number);
    
    return number;
}

int main() {
    int number;
    FILE *in = fopen("task.in", "r");
    
    number = intScan(in);
    fclose(in);
    printf("%d\n", number);
    
    return 0;
}
