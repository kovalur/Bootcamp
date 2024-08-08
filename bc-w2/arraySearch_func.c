#include <stdio.h>

int arraySearch(int array[], int size, int needle) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] == needle ) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, '\0'};
    int needle = 4;
    int index;
    
    
    index = arraySearch(array, size, needle);
    printf("%d\n", index); 
    
    return 0;
}

/*
Задача arraySearch()

Условие задачи
Написать функцию, возвращающую индекс искомого числа в массиве либо -1 в случае,
если число в массиве не содержится.
int arraySearch(int array[], int size, int needle)
*/
