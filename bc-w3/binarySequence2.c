#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char temp;
    int swaps = 0;
    int zeros = 0;
    
    for ( ; fscanf(in, "%c", &temp) != EOF; ) {
        if ( temp == '0' ) {
            zeros += 1;
        }
    }
    
    rewind(in);
    for ( int i = 0; fscanf(in, "%c", &temp) != EOF && i < zeros; i++ ) {
        if ( temp == '1' ) {
            swaps += 1;
        }
    }
    fclose(in);

    fprintf(out, "%d\n", swaps);
    fclose(out);

    return 0;
}

/*
Задача binarySequence2

Условие задачи
В файле task.in дана последовательность символов – нулей и единиц. Вывести в task.out минимально необходимое число обменов пар значений для упорядочивания последовательности по неубыванию.

Пример ввода
1101
Пример вывода
1

Пояснение
Необходимо обменять ноль с первой единицей.
*/
