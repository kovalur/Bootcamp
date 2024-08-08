#include <stdio.h>

int main() {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    printf("%d AND %d is %d\n", x, y, x&&y);
    printf("%d OR %d is %d\n", x, y, x||y);
    
    return 0;
}

/*
Задача logic

Условие задачи
Считать с клавиатуры два целых числа.
Вывести результат логических действий И и ИЛИ.

Пример ввода
0 1
Пример вывода
0 AND 1 is 0
0 OR 1 is 1
*/
