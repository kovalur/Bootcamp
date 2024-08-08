#include <stdio.h>

int scanSize(FILE *in) {
    int size = 0;
    
    for ( int temp; fscanf(in, "%1d", &temp) == 1; size++ );
    
    return size;
}

void fileScan(FILE *in, int array[], int size) {
    for ( int i = 0; fscanf(in, "%1d", &array[i]) == 1 && i < size; i++ );
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = scanSize(in);
    int seqArray[size];
    int swaps = 0;
    int head = 0;
    
    rewind(in);
    fileScan(in, seqArray, size);
    fclose(in);
    
    for ( int j = size - 1; j > head; j-- ) {
        if ( seqArray[head] > seqArray[j] ) {
            swaps += 1;
            head += 1;
        } else if ( seqArray[head] == seqArray[j] && seqArray[head] == 0 ) {
            head += 1;
            j += 1;
        }
    }
    
    fprintf(out, "%d\n", swaps);
    fclose(out);
    
    return 0;
}

/*
Задача binarySequence

Условие задачи
В файле task.in дана последовательность символов – нулей и единиц. Вывести в task.out минимально необходимое число обменов пар значений для упорядочивания последовательности по неубыванию.

Пример ввода
1101
Пример вывода
1

Пояснение
Необходимо обменять ноль с первой единицей.
*/
