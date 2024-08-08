#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    if ( a == b ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}

/*
Задача isEqual

Условие задачи
Считать с клавиатуры 2 целых числа. Если они равны вывести на экран «yes», в противном случае вывести «no».

Пример ввода
-20 20
Пример вывода
no
*/
