import math  

def summ(num):
    summ = 0
    while num:
        summ += num % 10
        num //= 10
    return summ
 
a = int(input())
b = int(input())
 
if summ(a) > summ(b): print('a>b')
elif summ(b) > summ(a): print('b>a')
else: print('equal')
