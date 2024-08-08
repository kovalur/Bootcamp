#include <stdio.h>

void addressPointerIncrement(int **value) {
    // Updating address of variable in pointer
    *value += 1;
}

void pointerIncrement(int *value) {
    // Updating value in variable using pointer
    *value += 1;
}

int main() {
    int pre_x = 20;
    int x = 21;
    int y = 22;
    int z = 23;
    int *pointerX = &x;
    int *pointerY = &y;
    int *pointerZ = &z;
    
    // Test1
    
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    printf("Address of pointerX: %p\n", &pointerX);
    
    addressPointerIncrement(&pointerX);
    pointerIncrement(&x);
    
    printf("Value of x after incrementing with function: %d\n", x);
    printf("Address of x after incrementing with function: %p\n", &x);
    printf("Address of x value in pointerX after incrementing with function: %p\n", pointerX);
    printf("Dereference of value in pointerX after incrementing: %d\n", *pointerX);
    printf("Address of pointerX after incrementing: %p\n", &pointerX);
    
    // // Extra related tests
    
    // printf("Value of x: %d\n", x);
    // printf("Value of y: %d\n", y);
    // printf("Value of z: %d\n", z);
    // printf("Address of x: %p\n", &x);
    // printf("Address of y: %p\n", &y);
    // printf("Address of z: %p\n", &z);
    // printf("Dereference of value in pointerX: %d\n", *pointerX);
    // printf("Dereference of value in pointerX: %d\n", *pointerY);
    // printf("Dereference of value in pointerX: %d\n", *pointerZ);
    // printf("Address of pointerX: %p\n", &pointerX);
    // printf("Address of pointerY: %p\n", &pointerY);
    // printf("Address of pointerZ: %p\n", &pointerZ);
    // printf("Address of x value in pointerX: %p\n", pointerX);
    // printf("Address of y value in pointerY: %p\n", pointerY);
    // printf("Address of z value in pointerZ: %p\n", pointerZ);
    
    // pointerX += 1;
    // pointerY += 1;
    // pointerZ += 1;
    
    // printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    // printf("Value of x after incrementing: %d\n", x);
    // printf("Value of y after incrementing: %d\n", y);
    // printf("Value of z after incrementing: %d\n", z);
    // printf("Address of x after incrementing: %p\n", &x);
    // printf("Address of y after incrementing: %p\n", &y);
    // printf("Address of z after incrementing: %p\n", &z);
    // printf("Dereference of value in pointerX after incrementing: %d | was %d\n", *pointerX, x);
    // printf("Dereference of value in pointerY after incrementing: %d | was %d\n", *pointerY, y);
    // printf("Dereference of value in pointerZ after incrementing: %d | was %d\n", *pointerZ, z);
    // printf("Address of pointerX after incrementing: %p\n", &pointerX);
    // printf("Address of pointerY after incrementing: %p\n", &pointerY);
    // printf("Address of pointerZ after incrementing : %p\n", &pointerZ);
    // printf("Address of x value in pointerX after incrementing: %p\n", pointerX);
    // printf("Address of x value in pointerX after incrementing: %p\n", pointerY);
    // printf("Address of x value in pointerX after incrementing: %p\n", pointerZ);

    return 0;
}

/*
Задача pointerIncrement()

Условие задачи
void pointerIncrement(int *value)

Увеличить на единицу значение по переданному адресу value.
*/
