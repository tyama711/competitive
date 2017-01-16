import primesieve as ps
from math import sqrt
import itertools as it

n = 10**7
primes = ps.generate_primes(2*(int)(sqrt(n)))

# x must be under n
def factors(x):
    ans = []
    m = len(primes)
    p = primes[0]
    next = 1
    while p*p <= x:
        if x % p == 0:
            ans.append(p)
            x /= p
            continue
        p = primes[next]
        next += 1
    if x != 1:
        ans.append(x)
    return ans

# x must be under n
def numOfFactors(x):
    ans = 1
    for (k,g) in it.groupby(factors(x)):
        ans *= len(list(g)) + 1
    return ans

ys = [numOfFactors(i) for i in range(1,n+1)]
zs = ys[1:]
print(sum([1 for _ in filter(lambda a:a[0] == a[1], zip(ys,zs))]))
