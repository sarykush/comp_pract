//pow(e,-x)-sqrt(x-1)=0; eps=pow(10,-6) ==> x должен быть >=1
//дихотомия, итерации, хорды, ньютон

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

//функция
double f(double x){
    const double e = M_E;
    double func=pow(e,-1*x)-sqrt(x-1);
    return func;
}

//первая производная
double f1(double x){
    const double e = M_E;
    double func=-1*((pow(e,-1*x)*(pow(e,x)+2*sqrt(x-1)))/(2*sqrt(x-1)));
    return func;
}

//вторая производная
double f2(double x){
    const double e = M_E;
    double func=((pow(e,-1*x)*(pow(e,x)+sqrt(x-1)*(4*x-4)))/(sqrt(x-1)*(4*x-4)));
    return func;
}

void di(double eps){
    double a=1000, b=0, func;
    double x=(a+b)/2.0;
    double x_prev;
    while (abs(f(x))>eps){
        x_prev=x;
        func=f(a)*f(x);
        if(func>0){
            a=x;
            x=(a+b)/2.0;
        }else{
            b=x;
            x=(a+b)/2.0;
        }
    }
    if (x<1) x=x_prev;
    cout <<"метод дихотомии: x="<< x << endl;
    
}

void iter(double eps){
    double x=100;
    double x_prev;
    while ((abs(x-x_prev)>eps)){
        if (x<1) {
            x=x_prev;
            break;
        }
        x_prev=x;
        x=(log(sqrt(x-1)));
    }
    if (x<1) x=x_prev;
    cout <<"метод итераций: x="<< x << endl;
    
    
}

void newton(double eps){
    double a=1.01, b=2,x;
    if (f(a)*f2(a)>0) x=a;
    else x=b;
    double x_prev;
    while (abs(f(x))>eps){
        x_prev=x;
        x=x-f(x)/f1(x);
    }
    
    cout <<"метод ньютона: x="<< x << endl;
}

void chord(double eps){
    double a=1.01, b=2,x;
    if (f(a)*f2(a)>0) x=a;
    else x=b;
    double x_prev, x_prev1;
    while (abs(f(x))>eps){
        x_prev1=x_prev;
        x_prev=x;
        x=x_prev-f(x_prev)*(x_prev-x_prev1)/(f(x_prev)-f(x_prev1));
        
    }
    
    cout <<"метод хорд: x="<< x << endl;
}

int main(){   
    
    cout<<"f(1.1088): "<<f(1.1088)<<endl;
    double const eps = pow(10.0,-6);
    di(eps);
    iter(eps);
    newton(eps);
    chord(eps);
    
}
