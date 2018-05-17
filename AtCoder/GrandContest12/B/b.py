#! /usr/bin/env python3
from scipy.sparse import lil_matrix, csc_matrix, identity
from scipy.sparse.linalg import inv
import numpy as np
import sys

def query(mat, v, d, c, color):
    # acc1 = acc2 = identity(n, format='csc')
    # for i in range(d):
    #     acc1 = acc1 * mat
    #     acc2 = acc2 + acc1

    E = identity(n, format='csc')
    acc2 = inv(E - mat) * (E - mat**(d+1))
    
    vec = acc2.getcol(v-1)
    mask = vec.sign()
    color = color - color.multiply(mask)
    color = color + c*mask
    return color

data = map(int, sys.stdin.read().split())

n = next(data)
m = next(data)
mat = lil_matrix((n, n))

for i in range(m):
    a = next(data)
    b = next(data)
    mat[a-1, b-1] = 1
    mat[b-1, a-1] = 1
mat = mat.tocsc()

q = next(data)
color = csc_matrix([[0] for i in range(n)])

for i in range(q):
    v = next(data)
    d = next(data)
    c = next(data)
    color = query(mat, v, d, c, color)

for i in range(n):
    print(int(color[i,0]))
