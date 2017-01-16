#! /usr/bin/env python3

import itertools as it
import operator as op
import functools as ft

# n! / (n-m)!
def fact(n, m):
    return ft.reduce(op.mul, range((n-m)+1, n+1), 1)

def combi(n, m):
    return fact(n, m) // fact(m, m)

def f(n,d):
    if n < 4:
        return d**n
    return d**n - d*(sum(map(lambda m:d**(n-m-1) * combi(m, m-3) * f(m-3, d-1), range(3,n))))

print(f(18,10) // 10 * 9)
