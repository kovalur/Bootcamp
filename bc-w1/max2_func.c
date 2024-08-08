#include <stdio.h>

int max2(int x, int y) {
    if ( x > y ) {
        return x;
    }
    return y;
}
    
int main () {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    printf("%d\n", max2(x, y));
    
    return 0;
}

/*
Задача max2()

Условие задачи
Написать функцию
int max2(int x, int y)
*/
