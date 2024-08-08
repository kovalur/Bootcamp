#include <stdio.h>

int main() {
    for ( int attemptsLeft = 5; attemptsLeft >= 0; ) {
        int password;
        
        scanf("%d", &password);
        
        if ( attemptsLeft == 0 ) {
            printf("denied\n");
            return 0;
        } else if ( password == 1488 ) {
            printf("accepted\n");
            return 0;
        } else {
            printf("incorrect password\n");
            attemptsLeft -= 1;
        }
    }
    
    return 0;
}

/*
Задача password

Условие задачи
Считывать с клавиатуры пароль. Если пароль совпадает с 1488, вывести на экран "accepted", иначе вывести на экран "incorrect password". 
После пяти неудачных попыток вывести на экран "denied".

Пример ввода
1488
Пример вывода
accepted
*/
