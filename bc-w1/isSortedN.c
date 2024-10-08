#include <stdio.h>

int main() {
    int length;
    int sorted = 1;
    int current, previous;
    
    scanf("%d", &length);
    
    for ( int i = 1; i <= length; i++ ) {
        scanf("%d", &current);
        if ( current < previous && i > 1 ) {
            sorted = 0;
        }
        previous = current;
    }
    
    if ( sorted ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}

/*
Задача isSortedN

Условие задачи
Считать с клавиатуры положительную длину числовой последовательности и саму последовательность. Проверить, упорядочена ли последовательность по неубыванию. Если упорядочена вывести на экран «yes», в противном случае вывести «no».

Пример ввода
5
-20 -15 0 12 15
Пример вывода
yes
*/
