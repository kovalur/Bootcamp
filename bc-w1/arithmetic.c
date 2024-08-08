#include <stdio.h>

int main() {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    printf("%d+%d=%d\n", x, y, x+y);
    printf("%d-%d=%d\n", x, y, x-y);
    printf("%d*%d=%d\n", x, y, x*y);
    printf("%d/%d=%d\n", x, y, x/y);
    printf("%d%%%d=%d\n", x, y, x%y);
    
    return 0;
}

/*
Задача arithmetic

Условие задачи
Вывести результаты пяти разных арифметических действий над двумя введенными числами.

Пример ввода
1 2
Пример вывода
1+2=3
1-2=-1
1*2=2
1/2=0
1%2=1
*/
