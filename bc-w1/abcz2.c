#include <stdio.h>

int main() {
    int a;
    int toggle = 1;
    
    scanf("%d", &a);
    
    if ( a % 2 == 0 ) {
        printf("alpha\n");
        toggle = 0;
    }
    if ( a % 3 == 0 ) {
        printf("bravo\n");
        toggle = 0;
    }
    if ( a % 5 == 0 ) {
        printf("charlie\n");
        toggle = 0;
    }
    if ( toggle ) {
        printf("zulu\n");
    }
    
    return 0;
}

/*
Задача abcz2

Условие задачи
Считать с клавиатуры целое число.
- Если число четное, вывести alpha
- Если число кратно трем, вывести bravo
- Если число кратно пяти, вывести charlie
- Если число не кратно ни одному из них, вывести zulu

Пример ввода
8
Пример вывода
alpha
*/
