#include <stdio.h>

int main() {
    int x;
    
    scanf("%d", &x);
    
    if ( x % 2 == 0 ) {
        printf("%d\n", x/2);
    } else if ( x % 3 == 0 ) {
        printf("%d\n", x/3);
    } else {
        printf("%d\n", 0);
    }
    
    return 0;
}

/*
Задача maxDivisor

Условие задачи
Считать с клавиатуры целое положительное число. Вывести на экран наибольший его нетривиальный делитель. В случае неопределенности вывести 0.

Пример ввода
12
Пример вывода
6
*/
