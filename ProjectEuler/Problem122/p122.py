import itertools as it
import functools as ft

def iterate(f,x,recursion = 0):
    if recursion == 0:
        while True:
            yield x
            x = f(x)
    else:
        for _ in range(recursion + 1):
            yield x
            x = f(x)

def primes():
    ps = [2]
    yield 2
    cand = 3
    while True:
        for p in ps:
            if p*p > cand:
                ps.append(cand)
                yield cand
                break
            elif cand % p == 0:
                break
        cand += 2                
            
def factorize(n):
    pg = primes()
    p = next(pg)
    ret = []
    while p*p <= n:
        if n % p == 0:
            ret.append(p)
            n //= p
            continue
        p = next(pg)
    return ret + [n]

def divisors(n):
    fs = list(map(lambda x:list(x[1]), it.groupby(factorize(n))))
    gs = list(map(lambda xs:list(iterate(lambda y:xs[0]*y, 1, len(xs))), fs))
    return sorted(map(lambda xs:ft.reduce(lambda x,y:x*y, xs), it.product(*gs)))

def count_one_bits(n):
    count = 0
    while n > 0:
        if n % 2 == 1:
            count += 1
        n //= 2
    return count

def msb_of(n):
    count = -1
    while n > 0:
        count += 1
        n //= 2
    return count

# def m(k):
#     if k == 1:
#         return 0
#     fs = map(lambda xs:(xs[0], len(list(xs[1]))), it.groupby(factorize(k)))
#     return min(sum(map(lambda t:_m(t[0]) * t[1], fs)), _m(k))

def m(k):
    ds = divisors(k)
    xs = ds[1:(len(ds)+1)//2]
    if xs == []:
        return _m(k)
    a = min(map(lambda x:m(x)+m(k//x), xs))
    return min(a, _m(k))

def _m(k):
    return msb_of(k) + count_one_bits(k) - 1

print(sum(map(m, range(1,201))))
