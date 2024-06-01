//сложение, вычитание, умножение, возведение в степень 4, корень степени 3
//z1=1+i; z2=3-i; z3=-1+i

#include <iostream>
#include <cmath>
using namespace std;

class complex{
    private:
        int number;
    public:
        static int count;
        double v; 
        double i;
        complex(int a, int b);
        void print();
        complex operator +(const complex& z2);
        complex operator -(const complex& z2);
        complex operator =(const complex& z2);
        complex operator *(const complex& z2);
        void power(int n);
        void root(int n);
};

int complex::count = 0;

complex::complex(int a, int b){
    number=count;
    count++;
    v=a;
    i=b;
    cout << "Комплексному числу "<<v<<"+("<<b<<"*i) присвоен номер #"<<number<<endl;
}

void complex::print(){
    cout <<"Просмотр комплексного числа #"<<number<<":"<<endl;
    if (i<0) cout << v<<i<<"i"<<endl;
    else cout << v<<"+"<<i<<"i"<<endl;
}

complex complex::operator = (const complex& z2){
    cout<<"Приравниваем комплексное число #"<<number<<" к комплексному числу #"<<z2.number<<endl;
    v=z2.v;
    i=z2.i;
    return *this;
}

complex complex::operator + (const complex& z2){
    cout<<"Складываем комплексное число #"<<number<<" с комплексным числом #"<<z2.number<<endl;
    double v3, i3;
    v3=v+z2.v;
    i3=i+z2.i;
    complex tmp(v3, i3);
    return tmp;
}

complex complex::operator - (const complex& z2){
    cout<<"Складываем комплексное число #"<<number<<" с комплексным числом #"<<z2.number<<endl;
    double v3, i3;
    v3=v-z2.v;
    i3=i-z2.i;
    complex tmp(v3, i3);
    return tmp;
}

complex complex::operator * (const complex& z2){
    //(v+i)(v1+i1)=vv1+vi1+v1i+ii1
    cout<<"Умножаем комплексное число #"<<number<<" на комплексное число #"<<z2.number<<endl;
    double v3, i3;
    v3=(v*z2.v)-(i*z2.i);
    i3=(v*z2.i)+(i*z2.v);
    complex tmp(v3, i3);
    return tmp;
}

void complex::power (int n){
    cout<<"Возводим комплексное число #"<<number<<" в степень "<<n<<endl;
    double r, phi;
    r=sqrt(i*i+v*v);
    phi=acos(v/r);
    phi=phi*(180.0/3.14159265358979323846)*n;
    cout<<pow(r,n)<<"(cos("<<phi<<")+i*sin("<<phi<<"))"<<endl;
    /***
    
    double c=cos(n*phi);
    double s=sin(n*phi);
    cout<<pow(r,n)<<"("<<c<<"+i*"<<s<<")"<<endl;
    
    ***/
}

void complex::root (int n){
    cout<<"Извлекаем из комплексного числа #"<<number<<" корень степени "<<n<<endl;
    double r, phi;
    r=sqrt(i*i+v*v);
    phi=acos(v/r);
    double pi=3.14159265358979323846;
    phi=phi*(180.0/pi)*n;
    double j=180.0/phi;
    for (int k=0; k<n; k++){
        cout<<"k="<<k<<endl;
        cout<<pow(r,1.0/n)<<"(cos(("<<j+2.0*k<<"*pi)/"<<n<<")+i*sin(("<<j+2.0*k<<"*pi)/"<<n<<"))"<<endl;
    }
    /***
    
    double c=cos(n*phi);
    double s=sin(n*phi);
    cout<<pow(r,n)<<"("<<c<<"+i*"<<s<<")"<<endl;
    
    ***/
}

int main()
{
    double v1=1, i1=1, v2=3, i2=-1, v3=-1, i3=1;
    complex z1(v1, i1);
    complex z2(v2, i2);
    complex z3(v3, i3);
    
    complex tmp(0, 0);
    
    z1.print();
    z2.print();
    
    tmp=z1+z2;
    tmp=z1-z2;
    tmp=z1*z2;
    z3.power(4);
    z3.root(3);
    
}

