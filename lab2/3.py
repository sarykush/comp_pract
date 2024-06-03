'''
дано: парабола, точка
выяснить: принадлежит ли точка параболе
найти координату фокуса, расстояние от директрисы до фокуса
'''

import random
import math

class Dot:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Line:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c


random_generator = random.Random()
p1 = random_generator.randint(-100, 100)
d1 = Dot(random_generator.randint(-100, 100), random_generator.randint(-100, 100))

# форд фокус:
focus = Dot(0, p1/2.0)
print(f"фокус параболы y^2={2*p1}*x: ({focus.x}, {focus.y})")

# директриса y=-p/2 === y+0x+p/2=0
# расстояние до директрисы:
directrix = Line(0, 1, p1/2)
d = abs(directrix.a*focus.x + directrix.b*focus.y + directrix.c) / math.sqrt(directrix.a**2 + directrix.b**2)
print(f"растояние от фокуса до директриссы = {d}")

# принадлежит ли точка:
y1 = 2 * p1 * d1.x
if d1.y ** 2 == y1:
    print(f"точка ({d1.x}, {d1.y}) принадлежит параболе")
else:
    print(f"точка ({d1.x}, {d1.y}) НЕ принадлежит параболе")

