#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

void initPoint(Point *a) {
    scanf("%g %g", &(a->x), &(a->y));
} 

void pointPrint(Point a) {
    printf("(%g, %g)", a.x, a.y);
}

int pointEqual(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

double pointDistance(Point a, Point b) {
    return hypot(a.x-b.x, b.y-a.y);
}

int main() {
    Point a = {3, 3};
    Point b = {6, 7};
    
    initPoint(&a);
    initPoint(&b);
    
    pointPrint(a);
    printf("\n");
    pointPrint(b);
    printf("\n");
    printf("%d\n", pointEqual(a, b));
    printf("%g\n", pointDistance(a, b));
    if ( !pointEqual(a, b) ) {
        pointPrint(a);
        printf(" not equal to ");
        pointPrint(b);
        printf("\n");
    }
 
    return 0;
}
