import functools as ft
import sys

def iterate(f,x,recursion = 0):
    if recursion == 0:
        while True:
            yield x
            x = f(x)
    else:
        for _ in range(recursion + 1):
            yield x
            x = f(x)

def subtri(triangle, n, m, h):
    sub = [[0 for _ in range(i+1)] for i in range(h - n)]
    for i in range(h - n):
        for j in range(i+1):
            sub[i][j] = triangle[n+i][m+j]
    return sub

data = []
t = 0
for i in range(1000):
    xs = [0 for _ in range(i+1)]
    for j in range(i+1):
        t = (615949*t + 797807) & (2**20-1)
        xs[j] = t - 2**19
    data.append(xs[:])

mn = sys.maxsize
for h in range(1,101):
    for n in range(h):
        for m in range(n+1):
            sub = subtri(data, n, m, h)
            a = sum(map(sum, sub))
            if a < mn:
                mn = a
                print('h='+str(h)+',n='+str(n)+',m='+str(m))
print(mn)
