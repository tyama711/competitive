import itertools as it
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

def f(xs):
    t = (615949*xs[0] + 797807) & (2**20-1)
    return (t, t - 2**19)

n = 1000
t = 0
ans = sys.maxsize
data = list(it.islice(map(lambda xs:xs[1], iterate(f, (0, 0))), 1, n*(n+1)//2))
for i in range(n):
    for j in range(i+1):
        mn = sys.maxsize
        v = 0
        index = i * (i+1) // 2 + j
        for k in range(n-i):
            v += sum(data[index:index+k+1])
            if v < mn:
                mn = v
            index += i + k + 1
        if mn < ans:
            ans = mn
print(ans)
