import math

def f(x1, x2):
    return x1**2 + 3*x2**2 + math.cos(x1 + x2)

eps = 0.001
x2 = -100
x1 = -100
x_prev = -101
func = 0

print(f(x1, x2), f(x_prev, x2))

while f(x1, x2) < f(x_prev, x2):
    x_prev = x1
    x1 = x1 + eps
    func = f(x1, x2)
    print(f"x1={x1}; f={func}")
    print(f"x_prev={x_prev}")

x1 = x_prev
x_prev = -101

while f(x1, x2) < f(x1, x_prev):
    x_prev = x2
    x2 = x2 + eps
    func = f(x1, x2)
    print(f"x2={x2}; f={func}")
    print(f"x_prev={x_prev}")

x2 = x_prev

print(f"x1={x1}; x2={x2}")

