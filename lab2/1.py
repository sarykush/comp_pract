'''
три вектора на плоскости, случайные координаты. 
найти попарно углы, сумму и разность
выяснить,  нет ли среди них параллельных
'''

import random
import math

class Vector:
    count = 0

    def __init__(self):
        self.dim = 2
        self.v = [random.randint(-100, 100) for _ in range(self.dim)]
        self.number = Vector.count
        Vector.count += 1
        print(f"Created vector with random coordinates #{self.number}")

    def __str__(self):
        return f"Vector #{self.number}: {' '.join(map(str, self.v))}"

    def __add__(self, other):
        print(f"Adding vector #{self.number} with vector #{other.number}")
        return Vector([x + y for x, y in zip(self.v, other.v)])

    def __sub__(self, other):
        print(f"Subtracting vector #{other.number} from vector #{self.number}")
        return Vector([x - y for x, y in zip(self.v, other.v)])

    def __eq__(self, other):
        print(f"Equating vector #{self.number} with vector #{other.number}")
        return self.v == other.v

def angle(v1, v2):
    print(f"Angle between vectors #{v1.number} and #{v2.number}")
    dot_product = sum(x * y for x, y in zip(v1.v, v2.v))
    magnitude1 = math.sqrt(sum(x ** 2 for x in v1.v))
    magnitude2 = math.sqrt(sum(x ** 2 for x in v2.v))
    ang = math.acos(dot_product / (magnitude1 * magnitude2))
    ang_deg = ang * (180 / math.pi)
    print(f"{ang_deg:.2f} degrees; {ang:.2f} radians")
    return ang

def is_parallel(v1, v2):
    print(f"Checking if vectors #{v1.number} and #{v2.number} are parallel")
    a = v1.v[0] / v2.v[0]
    b = v1.v[1] / v2.v[1]
    if a == b:
        print("Vectors are collinear")
        return True
    else:
        print("Vectors are not collinear")
        return False

v0 = Vector()
v1 = Vector()
v2 = Vector()

print(v0)
print(v1)
print(v2)

angle(v1, v0)
angle(v2, v0)
angle(v2, v1)

print(v1 + v2)
print(v1 - v2)
print(v1 + v0)
print(v1 - v0)
print(v0 + v2)
print(v0 - v2)

is_parallel(v0, v1)
is_parallel(v1, v2)
is_parallel(v0, v2)
is_parallel(v1, v1)

