#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    
    *a = *b;
    *b = temp;
}

int partition(int array[], int start, int end) {
    int pivot = start + (end - start) / 2;
    int i = start - 1;
    
    swap(&array[pivot], &array[end]);
    
    for ( int j = start; j < end; j++ ) {
        if ( array[j] <= array[end] ) {
            i += 1;
            swap(&array[i], &array[j]);
        }
    }
    
    i += 1;
    swap(&array[i], &array[end]);
    
    return i;
}

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

void quickSort(int array[], int start, int end) {
    if ( start < end ) {
        int pivot = partition(array, start, end);
        
        quickSort(array, start, pivot-1);
        quickSort(array, pivot+1, end);
    }
}

void printArray(int array[], int size) {
    int last = size - 1;

    printf("{");
    for ( int i = 0; i < last; i++ ) {
        printf("%d, ", array[i]);
    }
    if ( size > 0 ) {
        printf("%d};\n", array[last]);
    } else {
        printf("};\n");
    } 
}

void writeToFile(FILE *out, int array[], int size) {
    int limit = size - 1;
    
    for ( int i = 0; i < limit; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[limit]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = lenScan(in);
    int start = 0;
    int end = len - 1;
    int sequence[len];
    
    arrayScan(in, sequence, len);
    fclose(in);
    
    printArray(sequence, len);
    
    quickSort(sequence, start, end);
    
    printArray(sequence, len);
    
    writeToFile(out, sequence, len);
    fclose(out);
    
    return 0;
}
