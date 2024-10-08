#include <stdio.h>

int main() {
    int length, number;
    
    scanf("%d", &length);
    
    for ( ; length > 0; length-- ) {
        scanf("%d", &number);
        printf("%d\n", number^42);
    }
    
    return 0;
}

/*
Задача frob

Условие задачи
Ввести положительную длину последовательности чисел, затем саму
последовательность.
Вывести искаженную последовательность, полученную применением к исходным членам
побитовой операции xor с числом 42.
Каждый член вывести на отдельной строке.

Пример ввода
2
0 42
Пример вывода
42
0
*/
