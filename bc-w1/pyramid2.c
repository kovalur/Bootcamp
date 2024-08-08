#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = 1, counter = 0; row <= total; row++ ) {
        for ( int col = 1; col < row; col++ ) {
            counter += 1;
            printf("%d ", counter);
        }
        counter += 1;
        printf("%d\n", counter);
    }
    
    return 0;
}

/*
Задача pyramid2

Условие задачи
Вывести числовую пирамидку на total строк.
В первой строке стоит число 1. В последующих строках стоят увеличивающиеся числа
через пробел.

Пример ввода
3
Пример вывода
1
2 3
4 5 6
*/
