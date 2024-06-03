//Метод Якоби с произвольной размерностью матрицы
#include <iostream>
using namespace std;

double C[3] {0, 0, 0};
int N=3, k;

void print_vect(double *v){
    for (int i=0;i<N;i++){
        cout<<v[i]<<"  ";
    }
    cout<<"\n";
}
 
double* mul_vect(double**matr, double*vect){
    for (int p = 0; p < N; p++)
    {
        C[p] = 0;
        for (k = 0; k < N; k++)
        {
            C[p] = C[p] + matr[p][k] * vect[k];
        }
    }
    return C;
}

double **antimatr(double**matr, double**target){
    for (int i=0;i<N;i++){
        for(int k=0; k<N;k++){
            if (k==i)
                target[i][k]=1/matr[i][k];
            else target[i][k]=0;
        }
    }
    return target;
}

double** diag_null(double**matr, double**target){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j) target[i][j] = 0;
            else if (i != j) target[i][j] = matr[i][j];
        }
    }
    return target;
}

int main()
{
    int x = 1;
    int y;
    int iter=100;
    
    int d=3;

    double b[3] {-1, 0, 2};
    double xx[3] {0, 0, 0};
    
    //матрица коэффициентов
    double** matr = new double*[d];
    for (int i = 0; i < d; i++) {
        matr[i] = new double[d];
    }
    
    matr[0][0]=-10; matr[0][1]=-1; matr[0][2]=3; 
    matr[1][0]=8; matr[1][1]=7; matr[1][2]=2; 
    matr[2][0]=6; matr[2][1]=6; matr[2][2]=2; 

    //антиматрица
    double** antim = new double*[d];
    for (int i = 0; i < d; i++) {
        antim[i] = new double[d];
    }
    antimatr(matr, antim);

    //обнулить главную диагональ
    double** ndiag = new double*[d];
    for (int i = 0; i < d; i++) {
        ndiag[i] = new double[d];
    }
    diag_null(matr, ndiag);
    
    double temp[3] {0, 0, 0};

    //якоби
    while (x <= iter)
    {
        mul_vect(ndiag, xx);
        for (int i = 0; i < N; i++) temp[i] = b[i] - C[i];
        mul_vect(antim, temp);
        for (int y = 0; y < N; y++) xx[y] = C[y]; 
        x++;
    }
    
    cout<<"x1:      x2:       x3:       "<<endl;
    print_vect(xx);
    return 0;
}
