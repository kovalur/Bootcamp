#include <stdio.h>

void selectSort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int minIndex = i;

        for ( int j = i + 1; j < size; j++ ) {
            if ( array[j] < array[minIndex] ) {
                minIndex = j;
            }
        }
        if ( minIndex != i ) {
            // Shift instead of pure swap to make algorithm stable
            int temp = array[minIndex];

            for ( int k = minIndex; k > i; k-- ) {
                array[k] = array[k-1];
            }
            array[i] = temp;
        }

        // if ( minIndex != i ) {
        //     int temp = array[minIndex];

        //     array[minIndex] = array[i];
        //     array[i] = temp;
        // }
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
