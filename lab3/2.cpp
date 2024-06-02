/***
метод прямоугольников, трапеций, параболоид
численное интегрирование
неопределенный интеграл
***/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath> 
#include<limits>
using namespace std;

double f(double x){
    const double e = M_E;
    return pow(e,-2*x)*sin(11*x);
}

double rectangleMethod(double a, double n, double h) {
    double sum = 0;
    double start = a+0.5*h;
    for(int i = 0; i < n; i++) {
        sum += f(start + i*h);
    }

    return sum * h;
}

double rectangleEps(double eps){
    double a=0, n=1000, h=5;
    double i1 = rectangleMethod(a, n, h);
    n*=2;
    double i2 = rectangleMethod(a, n, h);
    while (abs(i1-i2)>eps){
        n*=2;
        double i1 = rectangleMethod(a, n, h);
        n*=2;
        double i2 = rectangleMethod(a, n, h);
    }
    return i2;
}

double trapMethod(double a, double n, double h) {
    double inf = numeric_limits<float>::infinity(); 
    double sum = 0;
    double start = 0.5*(f(a)+f(inf));
    for(int i = 0; i < n; i++) {
        sum += f(start + i*h);
    }

    return sum * h;
}

double trapEps(double eps){
    double a=0, n=1000, h=5;
    double i1 = rectangleMethod(a, n, h);
    n*=2;
    double i2 = rectangleMethod(a, n, h);
    while (abs(i1-i2)>eps){
        n*=2;
        double i1 = rectangleMethod(a, n, h);
        n*=2;
        double i2 = rectangleMethod(a, n, h);
    }
    return i2;
}

double SimpsonMethod(double a, double n, double h) {
    if ((int)n%2==1) n+=1;
    double inf = numeric_limits<float>::infinity(); 
    double sum = 0;
    double start = (f(a) + 4 * f(a + h) + f(inf));
    n=n/2;
    for(int i = 0; i < n; i++) {
        sum += 2.0*f(a+(2*i)*h) + 4*f(a+(2*i+1)*h);
    }

    return sum*h/3.0;
}

double SimpsonEps(double eps){
    double a=0, n=1000, h=5;
    double i1 = rectangleMethod(a, n, h);
    n*=2;
    double i2 = rectangleMethod(a, n, h);
    while (abs(i1-i2)>eps){
        n*=2;
        double i1 = rectangleMethod(a, n, h);
        n*=2;
        double i2 = rectangleMethod(a, n, h);
    }
    return i2;
}

int main()
{
    double const eps = pow(10.0,-6);
    double result = rectangleEps(eps);
    cout << "метод прямоугольников: " << result << endl;
    result = trapEps(eps);
    cout << "метод трапеций: " << result << endl;
    result = SimpsonEps(eps);
    cout << "метод Симпсона: " << result << endl;
}
