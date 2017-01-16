import primesieve as ps
import itertools as it
import operator as op
import functools as ft
import cProfile as cp

primes = set(ps.generate_primes(10**10))

def is_prime(n):
    return n in primes

def S(n,d):
    ret = 0
    for i in range(n, 0, -1):
        ls = list(filter(lambda x:x != d, range(0,10)))
        for xs in it.combinations_with_replacement(ls, n-i):
            for ys in map(lambda x:x[0],
                          it.groupby(sorted(
                              it.permutations(list(it.repeat(d,i)) + list(xs))))):
                if ys[0] == 0:
                    continue
                a = ft.reduce(lambda a, b:10*a + b, ys)
                if is_prime(a):
                    ret += a
        if ret != 0:
            return ret

for d in range(0,10):
    print(S(6,d))
            
print(sum(map(lambda d:S(6,d), range(0,10))))
