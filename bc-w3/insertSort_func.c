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

// NOT COMPLETED!
void insertSort(int array[], int size) {
    int last = size - 1;
    
    for (int i = 0; i < last; i++ )
    {
        for (int index = i, from = i + 1; index >= 0; index--)
        {
            if (array[from] < array[index])
            {
                int temp = array[index];

                printf("array[%d] = %d --> array[%d] = %d\n", index, array[index], from, array[from]);
                printf("\n######################################\n");
                array[index] = array[from];
                array[from] = temp;
                index = i;
            }
        }
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
