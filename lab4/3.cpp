#include <iostream>
using namespace std;
int d=4;
double eps=0.01;
int max_iter=10000;

void print_vect(double *v){
    int dim=4;
    for (int i=0;i<dim;i++){
        cout<<v[i]<<"  ";
    }
    cout<<"\n";
}

bool crit(double**matr){
    double sum;
    for (int i=0; i<d; i++){
        for (int j=0; j<d; j++){
            if (j==i){
                sum=0;
                for (int k=0; k<d; k++){
                    if (k!=i){
                        sum+=matr[i][k];
                    }
                }
                if (abs(sum)>abs(matr[i][j])) return false;
                else continue;
            }
        }
    }
    return true;
}

double*seidel(double**matr, double*b, double*x, double*xx){
    int k;
    bool s0=false,s1=false,s2=false,s3=false;
    double b0, b1,b2,b3;
    for (k=0; k<max_iter;k++){
        double tmp0=x[0];
        double tmp1=x[1];
        double tmp2=x[2];
        double tmp3=x[3];
        
        x[0]=(b[0]-matr[0][1]*tmp1-matr[0][2]*tmp2-matr[0][3]*tmp3)/matr[0][0];
        x[1]=(b[1]-matr[1][0]*x[0]-matr[1][2]*tmp2-matr[1][3]*tmp3)/matr[1][1];
        x[2]=(b[2]-matr[2][0]*x[0]-matr[2][1]*x[1]-matr[0][3]*tmp3)/matr[2][2];
        x[3]=(b[3]-matr[3][0]*x[0]-matr[3][1]*x[1]-matr[3][2]*tmp3)/matr[3][3];
        
        double tmp12=x[0];
        double tmp22=x[1];
        double tmp32=x[2];
        double tmp42=x[3];
        
        b0=abs(tmp12-tmp0);
        b1=abs(tmp22-tmp1);
        b2=abs(tmp32-tmp2);
        b3=abs(tmp42-tmp3);
        
        
        s0=b0<eps;
        s1=b1<eps;
        s2=b2<eps;
        s3=b3<eps;
        
        cout<<"итерация #"<<k<<endl;
        print_vect(x);
        
        if(s0==true&&s1==true&&s2==true&&s3==true) {
            cout<<"достигнута указанная точность на итерации #"<<k<<endl;
            break;
        }

    }
    return x;
}

int main()
{
    double h[d] {176, -111, 74, 76};
    double x[d] {0,0,0,0};
    double xx[d] {0,0,0,0};
    
    //матрица коэффициентов
    double** arr = new double*[d];
    for (int i = 0; i < d; i++) {
        arr[i] = new double[d];
    }

    arr[0][0]=15; arr[0][1]=0; arr[0][2]=7; arr[0][3]=5;
    arr[1][0]=-3; arr[1][1]=-14; arr[1][2]=-6; arr[1][3]=1;
    arr[2][0]=-2; arr[2][1]=9; arr[2][2]=13; arr[2][3]=2;
    arr[3][0]=4; arr[3][1]=-1; arr[3][2]=3; arr[3][3]=9;
    
    seidel(arr,h,x,xx);
}
