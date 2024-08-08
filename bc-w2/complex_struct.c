#include <stdio.h>
#include <math.h>

typedef struct {
    double re, im;
} Complex;

void initComplex(Complex *this) {
    scanf("%g %g", &(this->re), &(this->im));
}

void complexIncrement(Complex *this, Complex other) {
    this->re += other.re;
    this->im += other.im;
}

void complexDecrement(Complex *this, Complex other) {
    this->re -= other.re;
    this->im -= other.im;
}

void complexMultiply(Complex *this, Complex other) {
    Complex temp;
    
    temp.re = this->re;
    temp.im = this->im;
    this->re = temp.re * other.re - temp.im * other.im;
    this->im = temp.re * other.im + temp.im * other.re;
}

void complexDivide(Complex *this, Complex other) {
    Complex temp;
    
    temp.re = this->re;
    temp.im = this->im;
    this->re = (temp.re * other.re + temp.im * other.im) /
                (other.re * other.re + other.im * other.im);
    this->im = (temp.im * other.re - temp.re * other.im) /
                (other.re * other.re + other.im * other.im);
}

Complex complexSum(Complex a, Complex b) {
    Complex sum;
    
    sum.re = a.re + b.re;
    sum.im = a.im + b.im;
    return sum;
}

Complex complexDiff(Complex a, Complex b) {
    Complex diff;
    
    diff.re = a.re - b.re;
    diff.im = a.im - b.im;
    return diff;
}

Complex complexProduct(Complex a, Complex b) {
    Complex product;
    
    product.re = a.re * b.re - a.im * b.im;
    product.im = a.re * b.im + a.im * b.re;
    return product;
}

int complexEqual(Complex a, Complex b) {
    return a.re == b.re && a.im == b.im;
}

double complexAbs(Complex this) {
    return hypot(this.re, this.im);
}

void complexPrint(Complex this) {
    printf("%g%+gi", this.re, this.im);
}

int main() {
    int isEqual;
    double absA, absB;
    Complex a = {2.0, -1};
    Complex b = {-2, 1.0};
    Complex sum, diff, product;
    
    initComplex(&a);
    initComplex(&b);
    
    complexPrint(a);
    printf("\n");
    complexIncrement(&a, b);
    complexPrint(a);
    printf("\n");
    complexDecrement(&a, b);
    complexPrint(a);
    printf("\n");
    complexMultiply(&a, b);
    complexPrint(a);
    printf("\n");
    complexDivide(&a, b);
    complexPrint(a);
    printf("\n################\n");
    
    complexPrint(b);
    printf("\n");
    complexIncrement(&b, a);
    complexPrint(b);
    printf("\n");
    complexDecrement(&b, a);
    complexPrint(b);
    printf("\n");
    complexMultiply(&b, a);
    complexPrint(b);
    printf("\n");
    complexDivide(&b, a);
    complexPrint(b);
    printf("\n################\n");
    
    sum = complexSum(a, b);
    printf("sum : ");
    complexPrint(sum);
    printf("\n");
    diff = complexDiff(a, b);
    printf("diff : ");
    complexPrint(diff);
    printf("\n");
    product = complexProduct(a, b);
    printf("product : ");
    complexPrint(product);
    printf("\n");
    isEqual = complexEqual(a, b);
    complexPrint(a);
    printf("%s", isEqual ? " is equal to " : " is not equal to ");
    complexPrint(b);
    printf("\n");
    absA = complexAbs(a);
    printf("Absolute value of a : %g\n", absA);
    absB = complexAbs(b);
    printf("Absolute value of b : %g", absB);
    
    return 0;
}

/*
Задача complex_struct

Условие задачи
С помощью известных вам инструментов реализовать тип Complex для хранения
комплексных чисел.

Теория:
Комплексное число задается формулой a + bi, где a и b - вещественные числа, i =
sqrt(-1) (мнимая единица); a называют действительной частью (принято обозначать
re), b называют мнимой частью (принято обозначать im).

Действия над комплексными числами:
* Сравнение: a + bi = c + di означает, что a = c и b = d (два комплексных числа
равны между собой тогда и только тогда, когда равны их действительные и мнимые
части).
* Сложение: (a + bi) + (c + di) = (a + c) + (b + d)i
* Вычитание: (a + bi) - (c + di) = (a - c) + (b - d)i
* Умножение: (a + bi)*(c + di) = ...

Модуль комплексного числа вычисляется как квадратный корень из суммы квадратов
его действительной и мнимой частей.

void complexIncrement(Complex *this, Complex other)
void complexDecrement(Complex *this, Complex other)
void complexMultiply(Complex *this, Complex other)
Complex complexSum(Complex a, Complex b)
Complex complexDiff(Complex a, Complex b)
Complex complexProduct(Complex a, Complex b)
int complexEqual(Complex a, Complex b)
double complexAbs(Complex this) - нахождение модуля комплексного числа.
Воспользоваться функцией hypot() из библиотеки math.h
void complexPrint(Complex this) - печать комплексного числа в виде a+bi.
Воспользоваться шаблоном %g. Проследить за знаком мнимой части. Обеспечить
возможность вывода вида 3+7i is not equal to 4+2i.
*/
