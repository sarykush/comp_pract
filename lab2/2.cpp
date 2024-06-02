/***
три вектора в пространстве, случайные координаты. 
найти попарно углы, сумму и разность +
выяснить, не лежат ли в одной плоскости и нет ли среди них параллельных
найти смешанное произведение +
***/

#include <iostream>
#include <cmath> 
#include <random> 
using namespace std;

class vect{
    private:
        int dim=3;
        double* v;
        int number;
        friend double mul(vect& v1, vect& v2, vect& v3);
        friend double angle(vect& v1, vect& v2);
        friend bool isCollinear(vect& v1, vect& v2);
        friend bool isComplanar(vect& v1, vect& v2, vect& v3);
    public:
        static int count;
        vect();
        vect(int x);
        void print();
        vect& operator = (const vect& vect);
        vect operator + (const vect& vect);
        vect operator - (const vect& vect); 
};

int vect::count = 0;

vect::vect(){
    random_device rd;   
    mt19937 gen(rd());  
    uniform_int_distribution<> dist(-100,100);
    number = count;
    count ++;
    cout << "Создан вектор со случайными координатами #"<<number<<endl;
    v = new double[dim];
    for (int i=0;i<dim;i++){
        v[i]=dist(gen); //случайное число от 1 до 100
    }
}

vect::vect(int d){
    number = count;
    count ++;
    cout << "Cоздан нулевой вектор #"<<number<<endl;
    v = new double[dim];
    for (int i=0;i<dim;i++){
        v[i]=0;
    }
    
}

void vect::print(){
    cout <<"Вектор #"<<number<<":"<<endl;
    for (int i=0;i<dim;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

double angle(vect& v1, vect& v2){
    cout <<"Угол между векторами #"<<v1.number<<" и #"<<v2.number<<endl;
    double sum;
    for (int i=0;i<v1.dim;i++){
        sum += v1.v[i]*v2.v[i];
    }
    double ang = acos(sum/(sqrt(v1.v[0]*v1.v[0]+v1.v[1]*v1.v[1]+v1.v[2]*v1.v[2])*sqrt(v2.v[0]*v2.v[0]+v2.v[1]*v2.v[1]+v2.v[2]*v2.v[2])));
    double ang_deg = ang*(180.0/3.14159265358979323846);
    cout<<ang_deg<<" градусов; "<<ang<<" радиан";
    cout<<"\n";
    sum=0;
    return ang;
}

vect& vect::operator = (const vect& vect){
    cout<<"Equating vector #"<<number<<" with vector #"<<vect.number<<endl;
    dim = vect.dim;
    for (int i=0;i<dim;i++){
        v[i]=vect.v[i];
    }
    return *this;
}

vect vect::operator + (const vect& v1){
    cout<<"Складываем вектор #"<<number<<" с вектором #"<<v1.number<<endl;
    vect tmp(0);
    for (int i=0;i<dim;i++){
        tmp.v[i] = v1.v[i]+v[i];
    }
    tmp.print();
    return tmp;
    
}

vect vect::operator - (const vect& v1){
    cout<<"Вычитаем вектор #"<<number<<" из вектора #"<<v1.number<<endl;
    vect tmp(0);
    for (int i=0;i<dim;i++){
        tmp.v[i] = v[i]-v1.v[i];
    }
    tmp.print();
    return tmp;
    
}

double mul(vect& v1, vect& v2, vect& v3){
    cout<<"Считаем смешанное произведение векторов #"<<v1.number<<", #"<<v2.number<<", #"<<v3.number<<endl;
    vect tmp(0);
    double sum;
    tmp.v[0] = v1.v[1]*v2.v[2]-v1.v[2]*v2.v[1];
    tmp.v[1] = v1.v[0]*v2.v[2]-v1.v[2]*v2.v[0];
    tmp.v[2] = v1.v[0]*v2.v[1]-v1.v[1]*v2.v[0];
    for (int i=0;i<v1.dim;i++){
        sum+=tmp.v[i]*v3.v[i];
    }
    return sum;
    
}

bool isCollinear(vect& v1, vect& v2){
    cout<<"Проверка на колинеарность векторов #"<<v1.number<<" и #"<<v2.number<<endl;
    double a=v1.v[0]/v2.v[0];
    double b=v1.v[2]/v2.v[2];
    double c=v1.v[1]/v2.v[1];
    if (a==b&&b==c&&a==c) {
        cout << "v векторы коллинеарны"<<endl;
        return true;
    }
    else {
        cout << "x векторы не коллинеарны"<<endl;
        return false;
    }
}

bool isComplanar(vect& v1, vect& v2, vect& v3){
    cout<<"Проверка на компланарность векторов #"<<v1.number<<", #"<<v2.number<<", #"<<v3.number<<endl;
    if (mul(v1,v2,v3)==0) {
        cout << "v векторы компланарны"<<endl;
        return true;
    }
    else {
        cout << "x векторы не компланарны"<<endl;
        return false;
    }
}

int main()
{
    vect v0;
    vect v1;
    vect v2;
    
    v0.print();
    v1.print();
    v2.print();
    
    angle(v1, v0);
    angle(v2, v0);
    angle(v2, v1);
    
    v1+v2;
    v1-v2;
    v1+v0;
    v1-v0;
    v0+v2;
    v0-v2;
    
    cout<<mul(v0,v1,v2)<<endl;
    
    isCollinear(v0,v1);
    isCollinear(v1,v2);
    isCollinear(v0,v2);
    isCollinear(v1,v1);
    
    isComplanar(v0,v1,v2);
}
