#include <stdio.h>

int main() {
    int a;
    
    scanf("%d", &a);
    
    if ( a % 2 != 0 ) {
        a -= 1;
    }
    
    printf("%d\n", a);
    
    return 0;
}

/*
Задача prevEven

Условие задачи
Считать целое число. Вывести на экран максимальное четное число, не большее введенного.

Пример ввода
17
Пример вывода
16
*/
