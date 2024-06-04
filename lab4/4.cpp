#include <math.h>
#include <iostream>
#include <conio.h>
using namespace std;
 
int i,n,k,dim=5;
double t,z,q,d;
double eps[5];
double X[5]; 
double et[5];
 
void print_vect(double *v){
    for (int i=0;i<dim;i++){
        cout<<v[i]<<"  ";
    }
    cout<<"\n";
}

double* progonka(double**matr, double*b){
    n=dim-1;
    eps[0]=-matr[0][1]/matr[0][0];
    et[0]=b[0]/matr[0][0];
 
    for(i=1;i<n;i++){
        z=matr[i][i]+matr[i][i-1]*eps[i-1];
        eps[i]=-matr[i][i+1]/z;
        et[i]=(b[i]-matr[i][i-1]*et[i-1])/z;
    }
 
    X[n]=(b[n]-matr[n][n-1]*et[n-1])/(matr[n][n]+matr[n][n-1]*eps[n-1]);
 
    for(i=n-1;i>=0;i--) X[i]=eps[i]*X[i+1]+et[i];
    return X;
}
 
int main()
{
    double** arr = new double*[dim];
    for (int i = 0; i < dim; i++) {
        arr[i] = new double[dim];
    }
    
    arr[0][0]=-10; arr[0][1]=-1; arr[0][2]=0; arr[0][3]=0;arr[0][4]=0;
    arr[1][0]=-8; arr[1][1]=16; arr[1][2]=1; arr[1][3]=0;arr[1][4]=0;
    arr[2][0]=0; arr[2][1]=6; arr[2][2]=-16; arr[2][3]=6;arr[2][4]=0;
    arr[3][0]=0; arr[3][1]=0; arr[3][2]=-8; arr[3][3]=16;arr[3][4]=-5;
    arr[4][0]=0; arr[4][1]=0; arr[4][2]=0; arr[4][3]=5; arr[4][4]=-13;
    
    double h[5]{16, -110, 24, -3, 87}; 
    
    cout<<"x1:        x2:        x3:        x4:       x5:"<<endl;
    print_vect(progonka(arr, h));
    return 0;
}
