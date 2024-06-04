import numpy as np

i, n, k, dim = 0, 0, 0, 5
t, z, q, d = 0.0, 0.0, 0.0, 0.0
eps = np.zeros(5)
X = np.zeros(5)
et = np.zeros(5)

def print_vect(v):
    for i in range(dim):
        print(f"{v[i]}  ", end="")
    print()

def progonka(matr, b):
    global n, eps, et, X
    n = dim - 1
    eps[0] = -matr[0][1] / matr[0][0]
    et[0] = b[0] / matr[0][0]

    for i in range(1, n):
        z = matr[i][i] + matr[i][i-1] * eps[i-1]
        eps[i] = -matr[i][i+1] / z
        et[i] = (b[i] - matr[i][i-1] * et[i-1]) / z

    X[n] = (b[n] - matr[n][n-1] * et[n-1]) / (matr[n][n] + matr[n][n-1] * eps[n-1])

    for i in range(n-1, -1, -1):
        X[i] = eps[i] * X[i+1] + et[i]
    return X

arr = np.zeros((dim, dim))

arr[0] = [-10, -1, 0, 0, 0]
arr[1] = [-8, 16, 1, 0, 0]
arr[2] = [0, 6, -16, 6, 0]
arr[3] = [0, 0, -8, 16, -5]
arr[4] = [0, 0, 0, 5, -13]

h = [16, -110, 24, -3, 87]

print("x1:        x2:        x3:        x4:       x5:")
print_vect(progonka(arr, h))

