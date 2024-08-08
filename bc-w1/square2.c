#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    if ( size == 0 ) {
        return 0;
    }
    
    for ( int counter = 1; counter / size < size; counter++ ) {
        for ( ; counter % size > 0; counter++ ) {
            printf("%d ", counter);
        }
        printf("%d\n", counter);
    }
    
    return 0;
}

/*
Задача square2

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
1 2
3 4
*/
