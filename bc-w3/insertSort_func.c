#include <stdio.h>

#define SIZE 11

void printArray(int array[], int len)
{
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

// // With optimization
// void insertSort(int array[], int len) {
//     for ( int i = 1; i < len; i++ ) {
//         int idx = i;
//         int temp = array[i];
        
//         for ( int j = i - 1; j >= 0; j-- ) {
//             if ( array[i] < array[j] ) {
//                 idx = j;
//             }
//         }
//         for ( int k = i; k > idx; k-- ) {
//             array[k] = array[k-1];
//         }
//         array[idx] = temp;
//     }
// }

// Even more optimizations
void insertSort(int array[], int len) {
    for ( int i = 1; i < len; i++ ) {
        int key = array[i];
        int j = i - 1;
        
        while ( j >= 0 && array[j] > key ) {
            array[j+1] = array[j];
            j -= 1;
        }
        array[j+1] = key;
    }
}

int main() {
    int len = SIZE;
    int array[SIZE] = {24, 1, 0, 15, 23, 6, 18, 345, 6, 15, 0};

    printArray(array, len);
    printf("\n######################################\n");
    insertSort(array, len);
    printArray(array, len);

    return 0;
}
