#include <stdio.h>

int main() {
    int phoneNumber, callDuration;
    
    scanf("%d %d", &phoneNumber, &callDuration);
    
    if ( phoneNumber == 101 || phoneNumber == 102 || phoneNumber == 103 || phoneNumber == 104 || phoneNumber == 112 ) {
        printf("%d$\n", 0);
    } else if ( phoneNumber >= 1000000 && phoneNumber <= 9999999 ) {
        printf("%d$\n", 1*callDuration);
    } else if ( phoneNumber >= 100 && phoneNumber <= 999 ) {
        printf("%d$\n", 40*callDuration);
    } else {
        printf("%d\n", -1);
    }
    
    return 0;
}

/*
Задача callCost

Условие задачи
Считать с клавиатуры 2 целых числа - номер телефона и количество минут.
Стоимость минуты разговора составляет 1$ за звонок на городской номер и 40$ за звонок на короткий номер. За звонок по номерам специальных служб плата не взимается. В случае неопределенности вывести -1.

Пример ввода
1488666 10
Пример вывода
10$

Пояснение
Коротким номером считается любой трехзначный номер.
Городским номером считается любой семизначный номер.
Номера телефонов не могут начинаться с ноля.
Номера спецслужб: 101, 102, 103, 104, 112.
*/
