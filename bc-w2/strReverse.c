#include <stdio.h>

#define MAX_SIZE 101

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[MAX_SIZE];
    int len = 0;
    
    fscanf(in, "%100s", str);
    fclose(in);
    
    for ( ; str[len] != '\0'; len++ );
    
    for ( int i = 0, j = len - 1; i < j; i++, j-- ) {
        int temp = str[j];
        
        str[j] = str[i];
        str[i] = temp;
    }
    
    fprintf(out, "%s\n", str);
    fclose(out);
    
    return 0;
}

/*
Задача strReverse

Условие задачи
В файле task.in дана строка длиной не более 100 символов.
Прочитать строку в память и произвести ее реверс.
Результат вывести в task.out.

Пример ввода
hello
Пример вывода
olleh
*/
