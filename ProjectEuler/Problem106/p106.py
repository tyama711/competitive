import itertools as it
import operator as op
import functools as ft

# n! / (n-m)!
def fact(n, m):
    return ft.reduce(op.mul, range((n-m)+1, n+1))

def combi(n, m):
    return fact(n, m) // fact(m, m)

def f(n):
    count = 0
    for a in it.combinations(range(1,n), n // 2 - 1):
        mn = 0
        mx = 0
        s = 0
        for i in range(2 * (n // 2)):
            if i in [0] + list(a):
                s += 1
            else:
                s -= 1
            if s > mx:
                mx = s
            elif s < mn:
                mn = s
        if mn < 0 < mx:
            count += 1
    return count

def solve(n):
    ret = 0
    for i in range(4, n+1, 2):
        ret += combi(n,i) * f(i)
    return ret

print(solve(12))
