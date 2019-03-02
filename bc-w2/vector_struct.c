#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Vector;

void initVector(Vector *a) {
    scanf("%lg %lg", &(a->x), &(a->y));
}

void vectorIncrement(Vector *this, Vector other) {
    this->x += other.x;
    this->y += other.y;
}

void vectorDecrement(Vector *this, Vector other) {
    this->x -= other.x;
    this->y -= other.y;
}

int vectorEqual(Vector a, Vector b) {
    return a.x == b.x && a.y == b.y;
}

Vector vectorSum(Vector a, Vector b) {
    Vector sum;
    
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    return sum;
}

Vector vectorDiff(Vector a, Vector b) {
    Vector diff;
    
    diff.x = a.x - b.x;
    diff.y = a.y - b.y;
    return diff;
}

double vectorLen(Vector this) {
    return hypot(this.x, this.y);
}

void vectorPrint(Vector this) {
    printf("(%g, %g)", this.x, this.y);
}

int main() {
    int isEqual;
    Vector a = {-2.1, 5}; 
    Vector b = {1, 1};
    Vector diff;
    Vector sum;

    initVector(&a);
    initVector(&b);
    
    vectorPrint(a);
    printf("\n");
    printf("%g\n", vectorLen(a));
    vectorIncrement(&a, b);
    vectorPrint(a);
    printf("\n");
    vectorDecrement(&a, b);
    vectorPrint(a);
    printf("\n################\n");
    
    vectorPrint(b);
    printf("\n");
    printf("%g\n", vectorLen(b));
    vectorIncrement(&b, a);
    vectorPrint(b);
    printf("\n");
    vectorDecrement(&b, a);
    vectorPrint(b);
    printf("\n################\n");
    
    isEqual = vectorEqual(a, b);
    printf("Are vectors equal? %s\n", isEqual ? "Yes!" : "No!");
    diff = vectorDiff(a, b);
    vectorPrint(diff);
    printf("\n");
    sum = vectorSum(a, b);
    vectorPrint(sum);
    
    return 0;
}
