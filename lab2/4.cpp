/***
дано: параболоид, плоскость, прямая, точка
выяснить: пересекает ли плоскость или прямая параболоид, принадлежит ли точка параболоиду

решение вопроса о том, пересекает ли прямая, следует из параметрического уравнения для прямой 
т.к. генерация параметров параболоида >= 0, то плоскость НЕ пересекает параболоид только в том случае, если параллельна плоскости z и находится ниже ee
***/

#include <iostream>
#include <cmath> 
#include <random> 
using namespace std;

struct dot {
    double x;
    double y;
    double z;
};

struct parab {
    double p;
    double q;
};

struct plane {
    double a;
    double b;
    double c;
    double d;
    double x;
    double y;
    double z;
};

struct line {
    double x0;
    double y0;
    double z0;
    double vx;
    double vy;
    double vz;
};

//------------------------------------------------


int main()
{
    random_device rd;   
    mt19937 gen(rd());  
    uniform_int_distribution<> dist(0,100);
    
    parab p1;
    p1.p = dist(gen);
    p1.q = dist(gen);

    plane pl1;
    pl1.x = dist(gen);
    pl1.y = dist(gen);
    pl1.z = dist(gen);
    pl1.a = dist(gen);
    pl1.b = dist(gen);
    pl1.c = dist(gen);
    pl1.d = -1*(pl1.x*pl1.a+pl1.y*pl1.b*pl1.z*pl1.c);
    
    plane subpl1;
    pl1.x = 0;
    pl1.y = 0;
    pl1.z = 0;
    pl1.a = 0;
    pl1.b = 0;
    pl1.c = 1;
    pl1.d = -1*(pl1.x*pl1.a+pl1.y*pl1.b*pl1.z*pl1.c);

    line l1;
    l1.x0 = dist(gen);
    l1.y0 = dist(gen);
    l1.z0 = dist(gen);
    l1.vx = dist(gen);
    l1.vy = dist(gen);
    l1.vz = dist(gen);

    dot d1;
    d1.x = dist(gen);
    d1.y = dist(gen);
    d1.z = dist(gen);
    
    //принадлежит ли точка:
    double z1;
    z1=((d1.x*d1.x)/2.0*p1.p)+((d1.y*d1.y)/2.0*p1.q);
    if (d1.z==z1) cout << "точка принадлежит параболоиду"<<endl;
    else cout << "точка НЕ принадлежит параболоиду"<<endl;
    
    //пересекает ли прямая
    double n, k, z2, D1;
    n=(pow(l1.vx, 2)/(2.0*p1.p))+(pow(l1.vy, 2)/(2.0*p1.q));
    k=(l1.vx/p1.p)+(l1.vy/p1.q)+l1.vz;
    z2=l1.z0-(pow(l1.x0,2)/(2.0*p1.p))-(pow(l1.y0,2)/(2.0*p1.q));
    D1=k*k-(4*n*z2);
    if (D1>0) cout << "прямая пересекает параболоид"<<endl;
    else if (D1=0) cout << "прямая касается параболоида"<<endl;
    else cout << "прямая НЕ пересекает параболоид"<<endl;
    
    //пересекает ли плоскость: 
    if (pl1.a/subpl1.a==pl1.b/subpl1.b&&pl1.a/subpl1.a==pl1.c/subpl1.c&&pl1.b/subpl1.b==pl1.c/subpl1.c&&pl1.d<0) cout << "плоскость НЕ пересекает параболоид"<<endl;
    else cout << "плоскость пересекает параболоид"<<endl;
    
}
