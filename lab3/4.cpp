/***
бесконечный ряд (pow(-1,k))/(sin(k*x)+11+k*k) с точностью 10**-6
***/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath> 
#include <random>
using namespace std;

double f(double x, int k){
    double res=(pow(-1,k))/(sin(k*x)+11+k*k);
    return res;
}

int main()
{
    double const eps = pow(10.0,-6);
    random_device rd;   
    mt19937 gen(rd());  
    uniform_int_distribution<> dist(-100,100);
    double x=dist(gen);
    int k=1;
    double sum=f(x, k);
    while (abs(f(x, k)-f(x, k-1))>eps){
        k++;
        sum+=f(x, k);
    }
    cout << sum;
}
