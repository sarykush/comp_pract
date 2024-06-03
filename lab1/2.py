'''
pow(e,-x)-sqrt(x-1)=0; eps=pow(10,-6) ==> x должен быть >=1
дихотомия, итерации, хорды, ньютон
'''
import math

# функция
def f(x):
    return math.e**(-1*x)-math.sqrt(x-1)

# первая производная
def f1(x):
    return -1*((math.e**(-1*x)*(math.e**x+2*math.sqrt(x-1)))/(2*math.sqrt(x-1)))

# вторая производная
def f2(x):
    return (math.e**(-1*x)*(math.e**x+math.sqrt(x-1)*(4*x-4)))/(math.sqrt(x-1)*(4*x-4))

def di(eps):
    a = 1000.0
    b = 0.0
    x = (a + b) / 2.0
    x_prev = 0
    mod=abs(f(x))
    while mod>eps:
        x_prev = x
        func = f(a) * f(x)
        if func > 0:
            a = x
            x = (a + b) / 2.0
        else:
            b = x
            x = (a + b) / 2.0
        if x < 1:
            x = x_prev
            break
        mod=abs(f(x))
    print(f"метод дихотомии: x={x}")

def iter(eps):
    x = 100
    x_prev = 0
    while abs(x - x_prev) > eps:
        if x < 1:
            x = x_prev
            break
        x_prev = x
        x = math.log(math.sqrt(x - 1))
    if x < 1:
        x = x_prev
    print(f"метод итераций: x={x}")

def newton(eps):
    a = 1.01
    b = 2
    if f(a) * f2(a) > 0:
        x = a
    else:
        x = b
    x_prev = 0
    while abs(f(x)) > eps:
        x_prev = x
        x = x - f(x) / f1(x)
    print(f"метод Ньютона: x={x}")

def chord(eps):
    a = 1.01
    b = 2
    if f(a) * f2(a) > 0:
        x = a
    else:
        x = b
    x_prev = 1
    x_prev1 = 1
    while abs(f(x)) > eps:
        if x < 1:
            x = x_prev
            break
        x_prev1 = x_prev
        x_prev = x
        x = x_prev - ((f(x_prev)*(x_prev-x_prev1))/(f(x_prev)-f(x_prev1)))
    print(f"метод хорд: x={x}")

print(f"f(1.1088): {f(1.1088)}")
eps = 10**(-6)
di(eps)
iter(eps)
newton(eps)
chord(eps)
