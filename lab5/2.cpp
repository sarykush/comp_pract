/*****
 * полином лагранжа
 * y=sin(x); x={0.1*pi, 0.2*pi, 0.3*pi, 0.4*pi}
 * найти полином в точках (должен совпадать со значением функции)
 * вычислить погрешность интерполяции в точке 0.25*pi
 *****/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

struct dot { 
    double x, y; 
};

double lagrange(double xi) {
    const double pi=M_PI;
	static const int n=4;
	static double x[n]={0.1*pi, 0.2*pi, 0.3*pi, 0.4*pi};
	static double y[n]={sin(0.1*pi), sin(0.2*pi), sin(0.3*pi), sin(0.4*pi)};
	double L, l;
	int i, j;
	L=0;
	for (i=0; i<n; i++)
	{
		l=1;
		for (j=0; j<n; j++)
			if (i!=j)
				l*=(xi-x[j])/(x[i]-x[j]);
		L+=y[i]*l;
	}
	return L;
}

int main() {
    const double pi=M_PI;
    double x1=0.1*pi, x2=0.4*pi;
    double M;

    for (double x=x1; x<=x2; x+=0.1*pi) {
        double y=lagrange(x);
        if (y>M) M=y;
        cout<<x<<"   "<<y<<"   "<<sin(x)<< endl;
    }
    
    dot f1[1] = { 
        { 0.25*pi, sin(0.25*pi) } 
    }; 
    cout<<"-------------------------------"<<endl;
    double y1 = lagrange(0.25*pi);
        cout<<0.25*pi<<"   "<<y1<<"   "<<sin(0.25*pi)<<endl;
    cout<<"-------------------------------"<<endl;
    
    /***
    для погрешности: 
    f''''(x)=f(x), потому что синус
    поэтому вычислили максимально значение производной выше
    R(x)=(x-x0)(x-x1)(x-x2)(x-x3)f(e)/4!
    ***/
    
    double fact=1;
    double A;
    for (double i=1; i<=4; i++){
        fact=fact*i;
    }
    
    A=1;
    for (double x=x1; x<=x2; x+=0.1*pi) {
        double tmp=abs(0.25*pi-x);
        A*=tmp;
    }
    double R=M*A/fact;
    cout<<"погрешность <= "<<R<<endl;
    return 0;
}
