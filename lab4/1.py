import numpy as np
from math import pow

# Function to print matrices
def print_matr(matr):
    dim = 4
    for i in range(dim):
        for k in range(dim):
            print(matr[i][k], end=" ")
        print()
    print()

# Function to print vectors
def print_vect(v):
    dim = 4
    for i in range(dim):
        print(v[i], end="  ")
    print()

# Function to delete a row and column
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

# Function to calculate the determinant of a matrix
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

# Function to transpose a matrix
def transp(matr, tMatr, n):
    for i in range(n):
        for j in range(n):
            tMatr[j][i] = matr[i][j]

# Function to multiply a matrix by a matrix
def mul_matr(matr, matr1):
    dim = 4
    for i in range(dim):
        for k in range(dim):
            sum = 0
            for j in range(dim):
                sum += matr[i][j] * matr1[j][k]
                matr[i][j] = sum
    return matr

# Function to multiply a matrix by a vector
def mul_vect(matr, vect):
    dim = 4
    xx = [0] * dim
    for i in range(dim):
        sum = 0
        for k in range(dim):
            sum += matr[i][k] * vect[k]
        xx[i] = sum
    return xx

# Function to solve a system of linear equations using Gaussian elimination
def gauss_1(matr, v):
    dim = 4
    for i in range(dim):
        tmp = matr[i][i]
        v[i] /= tmp
        for j in range(dim, i - 1, -1):
            matr[i][j] /= tmp
        for j in range(i + 1, dim):
            tmp = matr[j][i]
            v[j] -= tmp * v[i]
            for k in range(dim, i - 1, -1):
                matr[j][k] -= tmp * matr[i][k]
    xx = [0] * dim
    xx[dim - 1] = v[dim - 1]
    for i in range(dim - 2, -1, -1):
        xx[i] = v[i]
        for j in range(i + 1, dim):
            xx[i] -= matr[i][j] * xx[j]
    return xx

# Function to calculate the inverse of a matrix
def obrmatr(matr):
    n = 4
    d = det(matr, n)
    obr_matr = np.zeros((n, n))
    tobr_matr = np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            m = n - 1
            temp_matr = np.zeros((m, m))
            kill(matr, n, temp_matr, i, j)
            obr_matr[i][j] = pow(-1.0, i + j + 2) * det(temp_matr, m) / d
    transp(obr_matr, tobr_matr, n)
    return tobr_matr

import numpy as np

def progonka(arr, h):
    n = len(h)
    x = np.zeros(n)
    
    # Forward sweep
    alpha = np.zeros(n)
    beta = np.zeros(n)
    
    alpha[0] = -arr[0][1] / arr[0][0]
    beta[0] = h[0] / arr[0][0]
    
    for i in range(1, n):
        alpha[i] = -arr[i][i+1] / (arr[i][i] + arr[i][i-1]*alpha[i-1])
        beta[i] = (h[i] - arr[i][i-1]*beta[i-1]) / (arr[i][i] + arr[i][i-1]*alpha[i-1])
    
    # Backward sweep
    x[n-1] = beta[n-1]
    for i in range(n-2, -1, -1):
        x[i] = alpha[i]*x[i+1] + beta[i]
    
    return x

import numpy as np

def obrmatr(arr):
    return np.linalg.inv(arr)

def gauss_1(arr, h):
    A = np.array(arr)
    b = np.array(h)
    x = np.linalg.solve(A, b)
    return x

def mul_vect(arr, h):
    A = np.array(arr)
    b = np.array(h)
    return np.dot(A, b)

def print_vect(x):
    print(f"{x[0]:.3f}   {x[1]:.3f}   {x[2]:.3f}   {x[3]:.3f}")


d = 4

h = np.array([-144, 25, -21, 103])
h2 = np.array([-144, 25, -21, 103])
    
    # Coefficient matrix
arr = np.array([[-8, 5, 8, -6],
                [2, 7, -8, -4],
                [-5, -4, 1, -6],
                [5, -9, -2, 8]])
    
arr2 = np.array([[-8, 5, 8, -6],
                [2, 7, -8, -4],
                [-5, -4, 1, -6],
                [5, -9, -2, 8]])
    
arr1 = obrmatr(arr2)
    
print("x1:      x2:      x3:       x4:")
print_vect(gauss_1(arr, h))
print_vect(mul_vect(arr1, h2))


