#include <stdio.h>

#define MAX_LENGTH 10

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int number;
    
    for ( int i = 1; fscanf(in, "%d", &number) == 1 && i < MAX_LENGTH; i++ ) {
        fprintf(out, "%d ", number);
    }
    fclose(in);
    fprintf(out, "%d\n", number);
    fclose(out);
    
    return 0;
}

/*
Задача array

Условие задачи
Считать в массив последовательность чисел длиной 10 из файла task.in.
Записать его через пробел в файл task.out.

Пример ввода
10 20 30 40 50 60 70 80 90 100
Пример вывода
10 20 30 40 50 60 70 80 90 100
*/
