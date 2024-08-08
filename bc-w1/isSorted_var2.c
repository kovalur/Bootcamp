#include <stdio.h>

int main() {
    int a, b, c, d, e;
    int isOrdered = 1;
    
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if ( a > b ) {
        isOrdered = 0;
    } else if ( b > c ) {
        isOrdered = 0;
    } else if ( c > d ) {
        isOrdered = 0;
    } else if ( d > e ) {
        isOrdered = 0;
    }
    if ( isOrdered ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}

/*
Задача isSorted

Условие задачи
Считать с клавиатуры числовую последовательность - 5 целых чисел. Проверить, упорядочена ли последовательность по неубыванию. Если упорядочена вывести на экран «yes», в протиивном случае вывести «no». Задача решается без использования циклов.

Пример ввода
-20 -15 0 12 15
Пример вывода
yes
*/
