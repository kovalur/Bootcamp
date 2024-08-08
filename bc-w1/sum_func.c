#include <stdio.h>
    
int sum(int x, int y) {
    return x + y;
}
    
int main () {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    printf("%d\n", sum(x, y));
    
    return 0;
}

/*
Задача sum()

Условие задачи
Написать функцию
int sum(int x, int y)
*/
