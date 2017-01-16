from itertools import *
from fractions import gcd

def div_pow(n, d):
    e = 0
    while n % d == 0:
        e += 1
        n /= d
    return e, n

def divide_square_and_not(n, p0 = 2):
    if n == 1:
        return 1, 1
    else:
        for p in takewhile(lambda p: p * p <= n, count(p0)):
            if n % p == 0:
                e, m = div_pow(n, p)
                s, t = divide_square_and_not(m, p + 1)
                return p ** (e / 2) * s, p ** (e % 2) * t
        else:
            return 1, n

def gcd2(a, c):
    d = gcd(a, c)
    s, t = divide_square_and_not(d)
    return s * t

for i in range(8,20):
    for j in range(8,20):
        print('{0},{1}:{2}'.format(i, j, gcd2(i,j)))
