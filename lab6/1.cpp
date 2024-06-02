/*****
 * метод покоординатного спуска
 * без заданной точности
 *****/


#include <iostream>
#include <cmath>
using namespace std;

double f(double x1, double x2){
    return x1*x1+3*x2*x2+cos(x1+x2); //квадраты => минимум зависит от модуля+значения косинуса, скорее всего около (0,0)
}

int main(){
    const double eps = 0.001;
    //х2 фиксирован, х1 меняется
    double x2=-100;
    double x1=-100, x_prev=-101, func;
    cout<<f(x1,x2)<<" "<<f(x_prev, x2)<<endl;
    while (f(x1, x2)<f(x_prev, x2)){
        x_prev=x1;
        x1=x1+eps;
        func=f(x1,x2);
        cout <<"x1="<<x1<<"; f="<<func<<endl;
        cout<<"x_prev="<<x_prev<<endl;
    }
    //x1 фиксирован на найденном значении, х2 меняется
    x1=x_prev;
    x_prev=-101;
    while (f(x1, x2)<f(x1, x_prev)){
        x_prev=x2;
        x2=x2+eps;
        func=f(x1,x2);
        cout <<"x2="<<x2<<"; f="<<func<<endl;
        cout<<"x_prev="<<x_prev<<endl;
    }
    x2=x_prev;
    
    cout<<"x1="<<x1<<"; x2="<<x2;
}
