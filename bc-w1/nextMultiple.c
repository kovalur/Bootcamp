#include <stdio.h>

int main() {
    int numerator, denominator, multiple;
    
    scanf("%d %d", &numerator, &denominator);
    
    if ( denominator < 0 ) {
        denominator *= -1;
    }
    
    multiple = numerator - numerator % denominator;
    
    if ( multiple < numerator ) {
        multiple += denominator;
    }
    
    printf("%d\n", multiple);
}

/*
Задача nextMultiple

Условие задачи
Считать с клавиатуры два целых числа - делимое и делитель, причем делитель не равен нулю.
Вывести на экран наименьшее число, кратное делителю, не меньшее делимого.

Пример ввода
15 6
Пример вывода
18
*/
