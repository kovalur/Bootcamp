#include <stdio.h>

int main() {
    int min, max, m, n;
    int gcd, lcm, multiple, minMultiple;
    
    scanf("%d %d %d %d", &min, &max, &m, &n);
    
    multiple = m * n;
    for ( ; m > 0 && n > 0; ) {
        m = m % n;
        if ( m != 0 ) {
            n = n % m;
        }
        if ( m == 0 ) {
            gcd = n;
        } else if ( n == 0 ) {
            gcd = m;
        }
    }
    lcm = multiple / gcd;
    
    minMultiple = min - min % lcm;
    if ( minMultiple < min ) {
        minMultiple += lcm;
    }
    
    for ( ; minMultiple <= max; minMultiple += lcm ) {
        printf("%d\n", minMultiple);
    }
    
    return 0;
}

/*
Задача divMN

Условие задачи
Считать с клавиатуры целые числа min, max, m, n, причём m и n положительные.
Вывести на экран в столбик целые числа от min до max включительно, которые без
остатка делятся как на m, так и на n.
В указанном промежутке гарантируется хотя бы одно число, подлежащее выводу.

Пример ввода
0 12 2 3
Пример вывода
0
6
12
*/
