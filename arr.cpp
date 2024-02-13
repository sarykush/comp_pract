#include <iostream> 
 
using namespace std; 
 
int main(void) 
{ 
    int n,k,t,i; 
    cout<<"arr size:";
    cin>>n; 
    const int N = n; 
    float a[N]; 
    float b[N];
    float c[N];
    for (i=0; i<N; ++i) cin>>a[i]; 
     
    for (i=0; i<N; i++){ 
        if (a[i]<0){
            b[k]=a[i];
            k++;
        }
        else {
            c[t]=a[i];
            t++;
        }
    }
    
    for (i=0; k<N; i++){ 
            b[k]=c[i];
            k++;
        }
    
     for (i=0; i<N; i++) { 
        cout << b[i] << " "; 
    }
     
}
