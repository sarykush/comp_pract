#include <iostream> 
#include <bits/stdc++.h> 
#include <string>
 
using namespace std; 
 
int main(void) 
{ 
    string n, n1, k, k1;
    cin>>n>>k;
    n1=n;
    k1=k;
    reverse(n.begin(), n.end());
    reverse(k.begin(), k.end());
    if (n1==n&&k1==k) cout<<"both";
    else if (n1==n||k1==k) cout<<"one of them";
    else cout<<"none";
     
}
