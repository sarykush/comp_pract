import math  
from math import sqrt

e = float(input('Введите e: '))
f = float(input('Введите f: '))
g = float(input('Введите g: '))
h = float(input('Введите h: '))

a = sqrt(pow(abs(e-(3/f)),3)+g)
b = math.sin(e)+pow(math.cos(h),3)
c = (g*33)/(e*f-3)

print(f'Значение a = {a}')
print(f'Значение b = {b}')
print(f'Значение c = {c}')
