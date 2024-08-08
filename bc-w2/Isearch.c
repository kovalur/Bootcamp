#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 100;
    int array[size];
    int len = 0;
    int needle;
    
    fscanf(in, "%d", &needle);
    
    for ( ; len < size && fscanf(in, "%d", &array[len]) == 1; len++ );
    fclose(in);
    
    for ( int i = 0; i < len; i++ ) {
        if ( array[i] == needle ) {
            fprintf(out, "%d\n", i);
            fclose(out);
            
            return 0;
        }
    }
    fprintf(out, "-1\n");
    fclose(out);
    
    return 0;
}

/*
Задача Isearch

Условие задачи
В файле task.in дано искомое число needle, а также последовательность чисел
размером не более 100 элементов.
Найти needle в массиве и вывести в файл task.out его индекс либо -1, если число
не найдено.

Пример ввода
40
10 20 30 40 50 60 70 80 90 100
Пример вывода
3
*/
