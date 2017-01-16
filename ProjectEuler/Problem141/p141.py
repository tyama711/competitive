from math import sqrt
from sympy import factorint

def isSquare(n):
    return n == (int(sqrt(n)))**2

n = 10**12
ans = 0
for r in range(1, int(sqrt(n))):
    fac = factorint(r)
    _r = 1
    for f in fac:
        _r *= f ** ((fac[f]+1) // 2)
    d = r + _r
    a = d**3 // r + r
    while a < n:
        if isSquare(a):
            ans += a
        d += _r
        a = d**3 // r + r
print(ans)
