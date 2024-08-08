#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int row = 1, counter = size * size; row <= size; row++ ) {
        counter -= (size - 1);
        for ( int col = 1; col < size; col++ ) {
            printf("%d ", counter);
            counter += 1;
        }
        printf("%d\n", counter);
        counter -= size;
    }
    
    return 0;
}

/*
Задача square2rev

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Порядок строк обратный.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
3 4
1 2
*/
