import math

class Vector:
    def __init__(self, x1, x2):
        self.x1 = x1
        self.x2 = x2

def f(x):
    return 7 * x.x1 ** 2 + 5 * x.x2 ** 2 + 2 * x.x1 * x.x2 + x.x1 - 10 * x.x2

def grad(x):
    grad = Vector(14 * x.x1 + 2 * x.x2 + 1, 2 * x.x1 + 10 * x.x2 - 10)
    return grad

def clos(x, grad, l):
    tmp = Vector(x.x1 - l * grad.x1, x.x2 - l * grad.x2)
    return tmp

def spusk(x, eps):
    v_new = x
    v_prev = Vector(0, 0)

    while abs(f(v_new) - f(v_prev)) > eps:
        v_prev = v_new
        g = grad(v_new)
        l = 0.001
        v_new = clos(v_new, g, l)

    return v_new

if __name__ == "__main__":
    x = Vector(1, 1)
    eps = 0.001
    result = spusk(x, eps)
    print(f"x1={result.x1}; x2={result.x2}")

