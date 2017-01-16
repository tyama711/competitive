import operator as op
import functools as ft
import math as mt

def compose(outer_func, inner_func):
    def composed(*args, **kwds):
        return outer_func(inner_func(*args, **kwds))
    return composed

def P(m):
    return ft.reduce(op.mul, [(i / ((m+1)/2))**i for i in range(1,m+1)], 1)

print(sum(map(compose(mt.floor, P), range(2,16))))
