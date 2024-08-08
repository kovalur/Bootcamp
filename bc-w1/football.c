#include <stdio.h>

int main() {
    int hostGoals, guestGoals;
    
    scanf("%d %d", &hostGoals, &guestGoals);
    
    if ( hostGoals > guestGoals ) {
        printf("Home team wins\n");
    } else if ( guestGoals > hostGoals ) {
        printf("Away team wins\n");
    } else {
        printf("Draw\n");
    }
    
    return 0;
}

/*
Задача football

Условие задачи
Считать с клавиатуры 2 целых положительных числа, количество забитых голов хозяевами и гостями на футбольном матче. 
Вывести на экран результат матча «Home team wins», «Away team wins», «Draw».

Пример ввода
7 0
Пример вывода
Home team wins
*/
