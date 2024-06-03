import math

def f(k):
    return (11.0/2**(k-1))+(((-1)**(k-1))/(2*(3**(k-1))));

eps=10**-6
eps_cur=1
summ=0.0 
k=0
while eps_cur>eps:
    k+=1
    summ+=f(k)
    eps_cur=abs(f(k)-f(k-1))
print(f"количество итераций до заданной точности: {k}")
print(f"сумма ряда: {summ}")
