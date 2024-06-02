/*****
 * метод наискорейшего спуска
 * фиксированный шаг 0.001, точность 0.001, начальное приближение (1,1)
 *****/


#include <iostream>
#include <cmath>
using namespace std;

struct vector
{
   double x1,x2;
};

double f(vector x){
    return 7*x.x1*x.x1+5*x.x2*x.x2+2*x.x1*x.x2+x.x1-10*x.x2; 
}

vector grad(vector x)
{
   vector grad;
   grad.x1=14*x.x1+2*x.x2+1;
   grad.x2=2*x.x1+10*x.x2-10;
   return grad;
}
 
//Функция вычисления нового приближения
vector clos(vector x, vector grad, double l)
{
   vector tmp;
   tmp.x1=x.x1-l*grad.x1;
   tmp.x2=x.x2-l*grad.x2;
   return tmp;
}
 

vector spusk(vector x, double eps)
{
   vector v_new=x;
   vector v_prev;
 
   while(abs(f(v_new)-f(v_prev))>eps){
        v_prev=v_new;
        vector g=grad(v_new);
        double l=0.001;
        v_new=clos(v_new,g,l); 
   }
 
   return v_new; 
}
 
int main()
{
   vector x;
   double eps=0.001;
 
   x.x1=1;
   x.x2=1;
   
   vector result=spusk(x,eps);
   cout<<"x1="<<result.x1<<"; x2="<<result.x2;
 
   return 0;
};
