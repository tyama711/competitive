# import pyprimes as pp
from functools import reduce
import primesieve as ps

def unfoldl(f, init, finish):
    acc = init
    while not finish(acc):
        acc, y = f(acc)
        yield y

def digitRoot(n):
    a = sum(unfoldl(lambda acc: (acc//10, acc%10), n, lambda x: x==0))
    if a >= 10:
        return digitRoot(a)
    else:
        return a

def factorGenerator(n):
    # it = pp.primes()
    # prime = next(it)
    it = ps.Iterator()
    prime = it.next_prime()
    count = 0
    while prime*prime <= n:
        if n % prime == 0:
            count += 1
            n //= prime
        elif count > 0:
            yield (prime, count)
            count = 0
            # prime = next(it)
            prime = it.next_prime()
        else:
            # prime = next(it)
            prime = it.next_prime()
    if prime == n:
        yield(prime, count+1)
    elif count > 0:
        yield(prime, count)
        yield(n, 1)
    else:
        yield (n, 1)

def divisorGen(n):
    factors = list(factorGenerator(n))
    nfactors = len(factors)
    f = [0] * nfactors
    while True:
        yield reduce(lambda x, y: x*y, [factors[x][0]**f[x] for x in range(nfactors)], 1)
        i = 0
        while True:
            f[i] += 1
            if f[i] <= factors[i][1]:
                break
            f[i] = 0
            i += 1
            if i >= nfactors:
                return

class p159:
    def __init__(self):
        self.cache = [0 for _ in range(1000000)]

    def mdrs(self, n):
        if self.cache[n-1] != 0:
            return self.cache[n-1]
        mx = digitRoot(n)
        divisors = list(divisorGen(n))
        if len(divisors) == 2:
            self.cache[n-1] = mx
            return mx
        for d in divisors[1:-1]:
            if self.mdrs(d) + self.mdrs(n//d) > mx:
                mx = self.mdrs(d) + self.mdrs(n//d)
        self.cache[n-1] = mx
        return mx

def solve_p159():
    obj = p159()
    return sum(map(obj.mdrs, range(2, 1000000)))

if __name__ == '__main__':
    solve_p159()
