#include <stdio.h>

int main() {
    int start, step, quantity;
    int current = 0;
    
    scanf("%d %d %d", &start, &step, &quantity);
    
    current = start;
    for ( ; quantity > 1; quantity-- ) {
        printf("%d_", current);
        current += step;
    }
    printf("%d\n", current);
    
    return 0;
}

/*
Задача ariProg

Условие задачи
Считать с клавиатуры три целых числа - первый член, шаг и количество членов
арифметической прогрессии. Вывести в строку через пробел члены заданной
прогрессии.
Задаваемое количество больше нуля.

Пример ввода
12 2 4
Пример вывода
12 14 16 18
*/
