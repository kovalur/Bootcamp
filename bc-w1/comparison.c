#include <stdio.h>

int main() {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    printf("%d<%d is %d\n", x, y, x<y);
    printf("%d>%d is %d\n", x, y, x>y);
    printf("%d<=%d is %d\n", x, y, x<=y);
    printf("%d>=%d is %d\n", x, y, x>=y);
    printf("%d==%d is %d\n", x, y, x==y);
    printf("%d!=%d is %d\n", x, y, x!=y);
    
    return 0;
}

/*
Задача comparison

Условие задачи
Вывести результаты, возвращаемые разными операторами сравнения, используя два
введенных числа.

Пример ввода
1 2
Пример вывода
1<2 is 1
1>2 is 0
1<=2 is 1
1>=2 is 0
1==2 is 0
1!=2 is 1
*/
