import math

def f(x):
    return (x**4)*((11+x*x)**(-1));

def rectangle(f, a, b, nseg):
    dx=(b-a)/nseg
    summ=0.0
    start = a+0.5*dx 
    for i in range(nseg+1):
        summ += f(start + i * dx)
    return summ * dx
    
def rectangle_eps(f, a, b, nseg, eps):
    i1 = rectangle(f, a, b, nseg)
    nseg *= 2
    i2 = rectangle(f, a, b, nseg)
    while abs(i1-i2) > eps:
        nseg *= 2
        i1 = rectangle(f, a, b, nseg)
        nseg *= 2
        i2 = rectangle(f, a, b, nseg)
    print("результат методa прямоугольников:",i2)
    print("количество разбиений:",nseg)
    
#######################################

def trap(f, a, b, nseg):
    dx=(b-a)/nseg
    summ = 0.5*(f(a)+f(b))
    for i in range(1, nseg):
        summ+=f(a+i*dx)
    return summ*dx

def trap_eps(f, a, b, nseg, eps):
    i1 = trap(f, a, b, nseg)
    nseg *= 2
    i2 = trap(f, a, b, nseg)
    while abs(i1-i2)>eps:
        nseg*=2
        i1 = trap(f, a, b, nseg)
        nseg*=2
        i2 = trap(f, a, b, nseg)
    print("\nрезультат методa трапеций:",i2)
    print("количество разбиений:",nseg)
    
#######################################

def simpson(func, a, b, nseg):
    if nseg % 2 == 1:
        nseg += 1
    dx=1.0*(b-a)/nseg
    summ =(f(a)+4*f(a+dx)+f(b))
    nseg = int(nseg/2)
    for i in range(1, nseg):
        summ += 2*f(a+(2*i)*dx)+4*f(a+(2*i+1)*dx)
    return summ*dx/3

def simpson_eps(f, a, b, nseg, eps):
    i1 = simpson(f, a, b, nseg)
    nseg *= 2
    i2 = simpson(f, a, b, nseg)
    while abs(i1-i2)>eps:
        nseg*=2
        i1 = simpson(f, a, b, nseg)
        nseg*=2
        i2 = simpson(f, a, b, nseg)
    print("\nрезультат методa симпсона:",i2)
    print("количество разбиений:",nseg)

eps=10.0**-6
a=1.0 
b=2.0
nseg=2 

rectangle_eps(f, a, b, nseg, eps)
trap_eps(f, a, b, nseg, eps)
simpson_eps(f, a, b, nseg, eps)
