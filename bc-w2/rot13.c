#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 101;
    char str[size];
    
    fscanf(in, "%100s", str);
    fclose(in);
    
    for ( int i = 0, ch = str[i]; ch != '\0'; i++, ch = str[i] ) {
        const int shift = 13;
        
        if ( ch >= 'a' && ch <= 'm' ) {
            str[i] = ch + shift;
        } else if ( ch > 'm' && ch <= 'z' ) {
            str[i] = ch - shift;
        } else if ( ch >= 'A' && ch <= 'M' ) {
            str[i] = ch + shift;
        } else if ( ch > 'M' && ch <= 'Z' ) {
            str[i] = ch - shift;
        }
    }
    fprintf(out, "%s\n", str);
    fclose(out);
    
    return 0;
}

/*
Задача rot13

Условие задачи
Считать из файла task.in в память строку длиной не более 100 символов.
Зашифровать её по алгоритму ROT13.
Результат вывести в task.out.

Пример ввода
balk
Пример вывода
onyx
*/
