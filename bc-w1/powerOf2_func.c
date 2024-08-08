#include <stdio.h>

#define BASE 2

int powerOf2(int exponent) {
    return 1 << exponent;
}

int main() {
    int exponent;

    scanf("%d", &exponent);
    powerOf2(exponent);

    return 0;
}

/*
Задача powerOf2()

Условие задачи
int powerOf2(int exponent)

Возвести 2 в данную целую неотрицательную степень.
Воспользоваться побитовыми операциями.
*/
