#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    
    *a = *b;
    *b = temp;
}

void selectSort(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        int minValueIdx = i;
        
        for ( int j = i + 1; j < size; j++ ) {
            if ( array[j] < array[minValueIdx] ) {
                minValueIdx = j;
            }
        }
        
        // int temp = array[minValueIdx];
        
        // // Shifting instead of swapping to make algorithm stable
        // for ( int k = minValueIdx; k > i; k-- ) {
        //     array[k] = array[k-1];
        // }
        // array[i] = temp;
        
        swap(&array[minValueIdx], &array[i]);
    }
}

void printArray(int array[], int len ) {
    int last = len - 1;

    printf("{");
    if (last > -1)
    {
        printf("%d", array[0]);
        if (last > 0)
        {
            printf(",");
            for (int i = 1; i < last; i++)
            {
                printf(" %d,", array[i]);
            }
            printf(" %d", array[last]);
        }
    }
    printf("};");
}

int main() {
    int size = 6;
    int arr[] = {5, 2, 9, 6, 9, 21};

    printArray(arr, size);
    selectSort(arr, size);
    printf("\n");
    printArray(arr, size);
    
    return 0;
}

/*
Задача selectSort()

Условие задачи
void selectSort(int array[], int size)
*/
