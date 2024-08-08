#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char ch1;
    int temp;
    double bufer, result;
    
    fscanf(in, "%lg%c", &bufer, &ch1);
    if ( ch1 == '*' || ch1 == '/' ) {
        result = 0;
    } else {
        result = bufer;
        bufer = 1;
    }
    for ( int i = 0; i < 100 && fscanf(in, "%d", &temp) == 1; i++ ) {
        char ch2;
        int lastReadStatus;
        
        lastReadStatus = fscanf(in, "%c", &ch2);
        if ( ch1 == '+' || ch1 == '-' ) {
            if ( ch2 == '+' || ch2 == '-' || ch2 == '\n' || lastReadStatus == EOF ) {
                if ( ch1 == '+' ) {
                    result += temp;
                } else if ( ch1 == '-' ) {
                    result -= temp;
                }
            } else if ( ch2 == '*' || ch2 == '/' || ch2 == '\n' || lastReadStatus == EOF ) {
                if ( ch1 == '+' ) {
                    bufer = temp;
                } else if ( ch1 == '-' ) {
                    bufer = -temp;
                }
                if ( ch2 == '\n' || ch2 == EOF ) {
                    result += bufer;
                }
            }
        } else if ( ch1 == '*' || ch1 == '/' ) {
            if ( ch1 == '*' ) {
                bufer *= temp;
            } else if ( ch1 == '/' ) {
                bufer /= temp;
            }
            if ( ch2 == '+' || ch2 == '-' || ch2 == '\n' || lastReadStatus == EOF ) {
                result += bufer;
            }
        }
        ch1 = ch2;
    }
    fclose(in);
    
    fprintf(out, "%g\n", result);
    fclose(out);
    
    return 0;
}

/*
Задача calc

Условие задачи
Считать из task.in строку не более 1000 символов, содержащую неотрицательные целые числа и знаки арифметических операций между ними: + - * /.
Количество арифметических действий в выражении не превышает 100.
Вычислить значение выражения и вывести его в task.out в формате %g.

Пример ввода
1+2*3/4
Пример вывода
2.5
*/
