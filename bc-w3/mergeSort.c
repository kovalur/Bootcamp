#include <stdio.h>

int lenScan(FILE *in) {
    int len;
    
    fscanf(in, "%d", &len);
    
    return len;
}

void arrayScan(FILE *in, int array[], int size) {
    int temp;
    
    for ( int i = 0; fscanf(in, "%d", &temp) != EOF && i < size; i++ ) {
        array[i] = temp;
    }
}

void printArray(int array[], int size) {
    int last = size - 1;
    
    printf("{");
    if (last > -1) {
        printf("%d", array[0]);
        if (last > 0) {
            printf(",");
            for (int i = 1; i < last; i++) {
                printf(" %d,", array[i]);
            }
            printf(" %d", array[last]);
        }
    }
    printf("};");
}

void writeToFile(FILE *out, int array[], int size) {
    int limit = size - 1;
    
    for ( int i = 0; i < limit; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[limit]);
}

void merge(int array[], int lo, int mid, int hi) {
    int i = 0;
    int j = 0;
    int k = lo;
    int n1 = mid - lo + 1;
    int n2 = hi - mid;
    int buf1[n1];
    int buf2[n2];
    
    for ( int i = 0, j = lo; i < n1; i++, j++ ) {
        buf1[i] = array[j];
    }
    printf("lo = %d; mid = %d; hi = %d; => ", lo, mid, hi);
    printArray(buf1, n1);
    printf("\n");
    
    for ( int i = 0, j = mid + 1; i < n2; i++, j++ ) {
        buf2[i] = array[j];
    }
    printf("lo = %d; mid = %d; hi = %d; => ", lo, mid, hi);
    printArray(buf2, n2);
    printf("\n");
    
    for ( ; i < n1 && j < n2; k++ ) {
        int a = buf1[i];
        int b = buf2[j];
        
        if ( a <= b ) {
            array[k] = a;
            i += 1;
        } else {
            array[k] = b;
            j += 1;
        }
    }
    
    for ( ; i < n1; i++, k++ ) {
        array[k] = buf1[i];
    }
    
    for ( ; j < n2; j++, k++ ) {
        array[k] = buf2[j];
    }
}

void mergeSort(int array[], int lo, int hi) {
    if ( lo < hi ) {
        int mid = lo + (hi - lo) / 2;
        
        mergeSort(array, lo, mid);
        mergeSort(array, mid+1, hi);
        
        merge(array, lo, mid, hi);
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = lenScan(in);
    int sequence[len];
    int lo = 0;
    int hi = len - 1;
    
    arrayScan(in, sequence, len);
    fclose(in);
    
    printf("\n");
    printArray(sequence, len);
    printf("\n");
    printf("\n");
    
    mergeSort(sequence, lo, hi);
    
    printf("\n");
    printArray(sequence, len);
    printf("\n");
    
    writeToFile(out, sequence, len);
    fclose(out);
    
    return 0;
}

/*
Задача mergeSort

Условие задачи
В файле task.in дано число len и массив размером len элементов.
Отсортировать элементы в порядке неубывания.
Использовать алгоритм mergeSort.
Результат записать в task.out
Допустимо использование рекурсии.
*/
