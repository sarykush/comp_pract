import numpy as np

C = [0, 0, 0]
N = 3

def print_vect(v):
    print(*v)

def print_matr(matr):
    for row in matr:
        print(*row)
    print()

def kill(matr, n, temp_matr, indRow, indCol):
    ki = 0
    for i in range(n):
        if i != indRow:
            kj = 0
            for j in range(n):
                if j != indCol:
                    temp_matr[ki][kj] = matr[i][j]
                    kj += 1
            ki += 1

def det(matr, n):
    temp = 0
    k = 1
    if n == 1:
        temp = matr[0][0]
    elif n == 2:
        temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1]
    else:
        for i in range(n):
            m = n - 1
            temp_matr = np.zeros((m, m))
            kill(matr, n, temp_matr, 0, i)
            temp += k * matr[0][i] * det(temp_matr, m)
            k = -k
    return temp

def mul_vect(matr, vect):
    for p in range(N):
        C[p]=0
        for k in range(N):
            C[p] = C[p]+matr[p][k] * vect[k]
    return C

def antimatr(matr, target):
    for i in range(N):
        for k in range(N):
            if k == i:
                target[i][k] = 1 / matr[i][k]
            else:
                target[i][k] = 0
    return target

def diag_null(matr, target):
    for i in range(N):
        for j in range(N):
            if i == j:
                target[i][j] = 0
            else:
                target[i][j] = matr[i][j]
    return target

x = 1
y = None
iter = 100
d = 3
b = np.array([-1, 0, 2])
xx = np.zeros(3)

    # матрица коэффициентов
matr = np.zeros((d, d))
matr[0, 0] = -10
matr[0, 1] = -1
matr[0, 2] = 3
matr[1, 0] = 8
matr[1, 1] = 7
matr[1, 2] = 2
matr[2, 0] = 6
matr[2, 1] = 6
matr[2, 2] = 2

    # антиматрица
antim = np.zeros((d, d))
antimatr(matr, antim)

    # обнулить главную диагональ
ndiag = np.zeros((d, d))
diag_null(matr, ndiag)

temp = np.zeros(3)

    # якоби
while x <= iter:
    mul_vect(ndiag, xx)
    for i in range(3):
        temp[i] = b[i] - C[i]
    mul_vect(antim, temp)
    for y in range(3):
        xx[y] = C[y]
    x += 1

print("x1:      x2:       x3:       ")
print_vect(xx)

submatr_x1 = np.zeros((d, d))
for i in range(d):
    for j in range(d):
        if j == 0:
            submatr_x1[i, j] = b[i]
        else:
            submatr_x1[i, j] = matr[i, j]

submatr_x2 = np.zeros((d, d))
for i in range(d):
    for j in range(d):
        if j == 1:
            submatr_x2[i, j] = b[i]
        else:
            submatr_x2[i, j] = matr[i, j]

submatr_x3 = np.zeros((d, d))
for i in range(d):
    for j in range(d):
        if j == 2:
            submatr_x3[i, j] = b[i]
        else:
            submatr_x3[i, j] = matr[i, j]

det_main = det(matr, 3)
x1 = det(submatr_x1, 3) / det_main
x2 = det(submatr_x2, 3) / det_main
x3 = det(submatr_x3, 3) / det_main
print(f"{x1}   {x2}   {x3}")
