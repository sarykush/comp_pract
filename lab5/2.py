import math

class Dot:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def lagrange(xi):
    n = 4
    x = [0.1 * math.pi, 0.2 * math.pi, 0.3 * math.pi, 0.4 * math.pi]
    y = [math.sin(0.1 * math.pi), math.sin(0.2 * math.pi), math.sin(0.3 * math.pi), math.sin(0.4 * math.pi)]
    L = 0
    for i in range(n):
        l = 1
        for j in range(n):
            if i != j:
                l *= (xi - x[j]) / (x[i] - x[j])
        L += y[i] * l
    return L

def main():
    pi = math.pi
    x1 = 0.1 * pi
    x2 = 0.4 * pi
    M = float('-inf')

    for x in [x1 + i * 0.1 * pi for i in range(4)]:
        y = lagrange(x)
        if y > M:
            M = y
        print(f"{x:.6f}   {y:.6f}   {math.sin(x):.6f}")

    print("-------------------------------")
    y1 = lagrange(0.25 * pi)
    print(f"{0.25 * pi:.6f}   {y1:.6f}   {math.sin(0.25 * pi):.6f}")
    print("-------------------------------")

    fact = 1
    for i in range(1, 5):
        fact *= i
    A = 1
    for x in [x1 + i * 0.1 * pi for i in range(4)]:
        A *= abs(0.25 * pi - x)
    R = M * A / fact
    print(f"погрешность <= {R:.6f}")

if __name__ == "__main__":
    main()
