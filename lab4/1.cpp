#include <iostream>
#include <cmath>
#include <limits>
typedef std::numeric_limits< double > dbl;
using namespace std;

void print_matr(double **matr){
    int dim=4;
    for (int i=0;i<dim;i++){
        for(int k=0; k<dim;k++){
            cout<<matr[i][k]<<" ";
        }
        cout<<"\n";

    }
    cout<<"\n";
}

void print_vect(double *v){
    int dim=4;
    for (int i=0;i<dim;i++){
        cout<<v[i]<<"  ";
    }
    cout<<"\n";
}

//функция вычеркивания строки и столбца
void kill(double **matr, int n, double **temp_matr, int indRow, int indCol)   
{
    int ki = 0; 
    for (int i = 0; i < n; i++){
        if(i != indRow){
            for (int j = 0, kj = 0; j < n; j++){
                if (j != indCol){
                    temp_matr[ki][kj] = matr[i][j];
                    kj++;
                }
            }
            ki++;       
        }
    }
}
 

//функция вычисления определителя матрицы
double det(double **matr, int n)  
{
    double temp; 
    int k = 1; 
    if (n == 1)
        temp = matr[0][0];
    else if (n == 2)
        temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
    else{
        for(int i = 0; i < n; i++){
            int m = n - 1; 
            double **temp_matr = new double * [m];
            for(int j = 0; j < m; j++)
                temp_matr[j] = new double [m];
            kill(matr, n, temp_matr, 0, i);
            temp = temp + k * matr[0][i] * det(temp_matr, m);
            k = -k;
        }
    }
    return temp;
}

void transp(double **matr, double **tMatr, int n){//
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            tMatr[j][i] = matr[i][j];

}

double** mul_matr(double**matr, double**matr1){
    int dim=4;
    for (int i=0; i<dim; i++){
        for (int k=0; k<dim; k++){
            int sum = 0; 
            for (int j = 0; j < dim; j++) {        
            sum += matr[i][j] * matr1[j][k]; 
            matr[i][j] = sum;
            }
        }    
    }
    return matr;
}

//матрица на вектор = вертикальный вектор
double* mul_vect(double**matr, double*vect){
    int dim=4;
    double sum;
    double*xx=new double[dim];
    for (int i=0; i<dim; i++){
        sum=0;
        for (int k=0; k<dim; k++){
            sum=sum+matr[i][k]*vect[k];    
        }
        xx[i]=sum;
    }
    return xx;
}

double* gauss_1(double** matr, double*v){
    int i,k, ki, j, dim=4;
    double tmp;
    for (i=0; i<dim; i++){
        tmp=matr[i][i];
        v[i]/=tmp;
        for (j=dim;j>=i;j--){
            matr[i][j]/=tmp;
        }
        for (j=i+1;j<dim;j++){
            tmp=matr[j][i];
            v[j]-=tmp*v[i];
            for (k=dim;k>=i;k--){
                matr[j][k]-=tmp*matr[i][k];
            }
          }
    }
    double* xx=new double[4];
    xx[dim-1] = v[dim-1];
    for (i=dim-2; i>=0; i--)
       {
           xx[i] = v[i];
           for (j=i+1;j<dim;j++) xx[i]-=matr[i][j]*xx[j];
       }

    return xx;
}



double**obrmatr(double **matr)
{
    int n=4;
    double d;

    double **obr_matr = new double * [n];
    double **tobr_matr = new double * [n];
    for(int i = 0; i < n; i++){
        obr_matr[i] = new double[n];
        tobr_matr[i] = new double[n];
    }
    d = det(matr, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int m = n - 1;
            double **temp_matr = new double * [m];
            for(int k = 0; k < m; k++)
                temp_matr[k] = new double[m];
            kill(matr, n, temp_matr, i, j);
            obr_matr[i][j] = pow(-1.0, i + j + 2) * det(temp_matr, m) / d;
            }
        }   
    transp(obr_matr, tobr_matr, n);
    return tobr_matr;
}

int main()
{
    int d=4;

    double h[4] {-144, 25, -21, 103};
    double h2[4] {-144, 25, -21, 103};
    
    //матрица коэффициентов
    double** arr = new double*[d];
    for (int i = 0; i < d; i++) {
        arr[i] = new double[d];
    }

    arr[0][0]=-8; arr[0][1]=5; arr[0][2]=8; arr[0][3]=-6;
    arr[1][0]=2; arr[1][1]=7; arr[1][2]=-8; arr[1][3]=-4;
    arr[2][0]=-5; arr[2][1]=-4; arr[2][2]=1; arr[2][3]=-6;
    arr[3][0]=5; arr[3][1]=-9; arr[3][2]=-2; arr[3][3]=8;
    
    double** arr2 = new double*[d];
    for (int i = 0; i < d; i++) {
        arr2[i] = new double[d];
    }

    arr2[0][0]=-8; arr2[0][1]=5; arr2[0][2]=8; arr2[0][3]=-6;
    arr2[1][0]=2; arr2[1][1]=7; arr2[1][2]=-8; arr2[1][3]=-4;
    arr2[2][0]=-5; arr2[2][1]=-4; arr2[2][2]=1; arr2[2][3]=-6;
    arr2[3][0]=5; arr2[3][1]=-9; arr2[3][2]=-2; arr2[3][3]=8;
    double**arr1=obrmatr(arr2);
    
    
    cout<<"x1:      x2:      x3:       x4:"<<endl;
    print_vect(gauss_1(arr,h));
    print_vect(mul_vect(arr1,h2));

}
