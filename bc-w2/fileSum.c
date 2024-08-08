#include <stdio.h>

int main() {
    int x, y;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%d %d", &x, &y);
    fclose(in);
    fprintf(out, "%d\n", x+y);
    fclose(out);
    
    return 0;
}

/*
Задача fileSum

Условие задачи
Считать два числа из файла task.in.
Записать их сумму в файл task.out.

Пример ввода
10 20
Пример вывода
30
*/
