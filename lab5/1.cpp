/*****
 * численное дифференциорование
 *****/


#include <iostream>
#include <cmath>
using namespace std;

double side(double y2,double y1,double h){
    return (y2-y1)/h;
}

double cent(double y2,double y1,double h){
    return (y2-y1)/(2*h);
}

int main()
{
    double y0=-0.5, y1=0.0, y2=0.5, y3=0.86603, y4=1;
    double h=1.0;
    double y2l, y2r, y2c;
    double y1l, y1r, y1c;
    double y3l, y3r, y3c;
   
    y2l=side(y2,y1,h);
    y2r=side(y3,y2,h);
    y2c=cent(y3,y1,h);
    
    y1l=side(y1,y0,h);
    y1r=side(y2,y1,h);
    y1c=cent(y2,y0,h);
    
    y3l=side(y3,y2,h);
    y3r=side(y4,y3,h);
    y3c=cent(y4,y2,h);
   
    cout<<"ПЕРВЫЕ ПРОИЗВОДНЫЕ:"<<endl;
    cout<<"с помощью левых разностей: f'(x=1)="<<side(y2,y1,h)<<endl;
    cout<<"с помощью правых разностей: f'(x=1)="<<side(y3,y2,h)<<endl;
    cout<<"с помощью центральных разностей: f'(x=1)="<<cent(y3,y1,h)<<endl;
    cout << "-------------------------"<<endl;
    cout<<"ВТОРЫЕ ПРОИЗВОДНЫЕ:"<<endl;
    cout<<"с помощью левых разностей по левым разностям: f'(x=1)="<<side(y2l,y1l,h)<<endl;
    cout<<"с помощью левых разностей по правым разностям: f'(x=1)="<<side(y2r,y1r,h)<<endl;
    cout<<"с помощью левых разностей по центральным разностям: f'(x=1)="<<side(y2c,y1c,h)<<endl;
    cout << "-------------------------"<<endl;
    cout<<"с помощью правых разностей по левым разностям: f'(x=1)="<<side(y3l,y2l,h)<<endl;
    cout<<"с помощью правых разностей по правым разностям: f'(x=1)="<<side(y3r,y2r,h)<<endl;
    cout<<"с помощью правых разностей по центральным разностям: f'(x=1)="<<side(y3c,y2c,h)<<endl;
    cout << "-------------------------"<<endl;
    cout<<"с помощью центральных разностей по левым разностям: f'(x=1)="<<cent(y3l,y1l,h)<<endl;
    cout<<"с помощью центральных разностей по правым разностям: f'(x=1)="<<cent(y3r,y1r,h)<<endl;
    cout<<"с помощью центральных разностей по центральным разностям: f'(x=1)="<<cent(y3c,y1c,h)<<endl;

};
