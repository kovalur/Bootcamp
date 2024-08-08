#include <stdio.h>

int arrayScan(FILE *in, int array[], int limit) {
    int len = 0;
    
    for ( ; len < limit && fscanf(in, "%d", &array[len]) == 1; len++ );
    
    return len;
}

int main() {
    int limit = 15;
    int size = 100;
    int array[size];
    int result;
    FILE *in = fopen("task.in", "r");
    
    result = arrayScan(in, array, limit);
    printf("%d\n", result);
    
    return 0;
}

/*
Задача arrayScan()

Условие задачи
int arrayScan(FILE *in, int array[], int limit)

Считать из файла in не более limit элементов в массив array.
Вернуть количество считанных элементов.
*/
