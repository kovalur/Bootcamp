#include <stdio.h>

void arrayMerge(int target[], int src1[], int len1, int src2[], int len2) {
    for ( int i = 0, j = 0, k = 0; i < len1 + len2; i++ ) {
        if ( j < len1 && k < len2 ) {
            int temp1 = src1[j];
            int temp2 = src2[k];
            
            if ( temp1 < temp2 ) {
                target[i] = temp1;
                j += 1;
            } else if ( temp1 == temp2 ) {
                target[i] = temp1;
                j += 1;
                i += 1;
                target[i] = temp1;
                k += 1;
            } else {
                target[i] = temp2;
                k += 1;
            }
        } else if ( j < len1 ) {
            target[i] = src1[j];
            j += 1;
        } else if ( k < len2 ) {
            target[i] = src2[k];
            k += 1;
        }
    }
}

void printArray(int array[], int len) {
    int last = len - 1;

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

int main() {
    int len1 = 5;
    int len2 = 7;
    int len = len1 + len2;
    int target[len];
    int src1[] = {0, 0, 1, 2, 5};
    int src2[] = {1, 2, 2, 4, 5, 5, 31};

    printArray(target, len);
    printf("\n######################################\n");
    arrayMerge(target, src1, len1, src2, len2);
    printArray(target, len);

    return 0;
}
