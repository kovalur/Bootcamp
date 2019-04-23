#include <stdio.h>

#define SIZE 11

void printArray(int array[], int size)
{
    int last = size - 1;

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

// // Without optimization
// void insertSort(int array[], int size) {
//     for ( int i = 1; i < size; i++ ) {
//         for ( int j = i - 1, k = i; j >= 0; j-- ) {
//             if ( array[k] < array[j] ) {
//                 int temp = array[j];

//                 array[j] = array[k];
//                 array[k] = temp;
//                 k = j;
//             }
//         }
//     }
// }

// With optimization
void insertSort(int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        int index = i;
        int temp = array[i];

        for ( int j = i - 1; j >= 0; j-- ) {
            if ( array[i] < array[j] ) {
                index = j;
            }
        }
        for ( int k = i; k > index; k-- ) {
            array[k] = array[k-1];
        }
        array[index] = temp;
    }
}

int main() {
    int size = SIZE;
    int array[SIZE] = {24, 1, 0, 15, 23, 6, 18, 345, 6, 15, 0};

    printArray(array, size);
    printf("\n######################################\n");
    insertSort(array, size);
    printArray(array, size);

    return 0;
}
