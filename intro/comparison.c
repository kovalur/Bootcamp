#include <stdio.h>

int main() {
    int x, y;

    scanf("%d %d", &x, &y);

    printf("%d<%d is %d\n", x, y, x<y);
    printf("%d>%d is %d\n", x, y, x>y);
    printf("%d<=%d is %d\n", x, y, x<=y);
    printf("%d>=%d is %d\n", x, y, x>=y);
    printf("%d==%d is %d\n", x, y, x==y);
    printf("%d!=%d is %d\n", x, y, x!=y);

    if ( x % y == 0 ) {
        printf("alpha\n");
    } else if ( x % 2 == 0 ) {
        printf("x is even!\n");
    } else {
        printf("x is odd!\n");
    }

    return 0;
}
