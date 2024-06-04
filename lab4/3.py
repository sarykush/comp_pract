import numpy as np

d = 4
eps = 0.01
max_iter = 10000

def print_vect(v):
    dim = 4
    print(" ".join(map(str, v)))

def crit(matr):
    for i in range(d):
        for j in range(d):
            if j == i:
                s = 0
                for k in range(d):
                    if k != i:
                        s += abs(matr[i][k])
                if abs(s) > abs(matr[i][j]):
                    return False
    return True

def seidel(matr, b, x, xx):
    for k in range(max_iter):
        tmp0 = x[0]
        tmp1 = x[1]
        tmp2 = x[2]
        tmp3 = x[3]
        
        x[0] = (b[0] - matr[0][1]*tmp1 - matr[0][2]*tmp2 - matr[0][3]*tmp3) / matr[0][0]
        x[1] = (b[1] - matr[1][0]*x[0] - matr[1][2]*tmp2 - matr[1][3]*tmp3) / matr[1][1]
        x[2] = (b[2] - matr[2][0]*x[0] - matr[2][1]*x[1] - matr[0][3]*tmp3) / matr[2][2]
        x[3] = (b[3] - matr[3][0]*x[0] - matr[3][1]*x[1] - matr[3][2]*tmp3) / matr[3][3]
        
        tmp12 = x[0]
        tmp22 = x[1]
        tmp32 = x[2]
        tmp42 = x[3]
        
        b0 = abs(tmp12 - tmp0)
        b1 = abs(tmp22 - tmp1)
        b2 = abs(tmp32 - tmp2)
        b3 = abs(tmp42 - tmp3)
        
        s0 = b0 < eps
        s1 = b1 < eps
        s2 = b2 < eps
        s3 = b3 < eps
        
        print(f"Iteration #{k}")
        print_vect(x)
        
        if s0 and s1 and s2 and s3:
            print(f"Reached desired accuracy at iteration #{k}")
            break
    
    return x

h = np.array([176, -111, 74, 76])
x = np.zeros(d)
xx = np.zeros(d)

arr = np.array([[15, 0, 7, 5],
                [-3, -14, -6, 1],
                [-2, 9, 13, 2],
                [4, -1, 3, 9]])

seidel(arr, h, x, xx)

