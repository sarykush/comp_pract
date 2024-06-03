import math

class Complex:
    count = 0

    def __init__(self, a, b):
        self.number = Complex.count
        Complex.count += 1
        self.v = a
        self.i = b
        print(f"Комплексному числу {a}+({b}*i) присвоен номер #{self.number}")

    def print(self):
        print(f"Просмотр комплексного числа #{self.number}:")
        if self.i < 0:
            print(f"{self.v}{self.i}i")
        else:
            print(f"{self.v}+{self.i}i")

    def __eq__(self, other):
        print(f"Приравниваем комплексное число #{self.number} к комплексному числу #{other.number}")
        self.v = other.v
        self.i = other.i
        return self

    def __add__(self, other):
        print(f"Складываем комплексное число #{self.number} с комплексным числом #{other.number}")
        v3 = self.v + other.v
        i3 = self.i + other.i
        return Complex(v3, i3)

    def __sub__(self, other):
        print(f"Вычитаем комплексное число #{other.number} из комплексного числа #{self.number}")
        v3 = self.v - other.v
        i3 = self.i - other.i
        return Complex(v3, i3)

    def __mul__(self, other):
        print(f"Умножаем комплексное число #{self.number} на комплексное число #{other.number}")
        v3 = (self.v * other.v) - (self.i * other.i)
        i3 = (self.v * other.i) + (self.i * other.v)
        return Complex(v3, i3)

    def power(self, n):
        print(f"Возводим комплексное число #{self.number} в степень {n}")
        r = math.sqrt(self.i**2 + self.v**2)
        phi = math.acos(self.v / r)
        phi = phi * (180.0 / math.pi) * n
        print(f"{r**n}(cos({phi})+i*sin({phi}))")

    def root(self, n):
        print(f"Извлекаем из комплексного числа #{self.number} корень степени {n}")
        r = math.sqrt(self.i**2 + self.v**2)
        phi = math.acos(self.v / r)
        pi = math.pi
        phi = phi * (180.0 / pi) * n
        j = 180.0 / phi
        for k in range(n):
            print(f"k={k}")
            print(f"{r**(1.0/n)}(cos(({j+2.0*k}*pi)/{n})+i*sin(({j+2.0*k}*pi)/{n}))")

v1, i1 = 1, 1
v2, i2 = 3, -1
v3, i3 = -1, 1

z1 = Complex(v1, i1)
z2 = Complex(v2, i2)
z3 = Complex(v3, i3)

z1.print()
z2.print()

tmp = z1 + z2
tmp = z1 - z2
tmp = z1 * z2
z3.power(4)
z3.root(3)
