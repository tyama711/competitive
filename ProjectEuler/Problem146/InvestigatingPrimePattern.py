import itertools
import random

def cand():
    i = 3
    while True:
        yield i
        i += 2

def primes():
    yield 2
    for p in cand():
        if isPrime(p):
            yield p

def isPrime(n):
    for d in itertools.takewhile(lambda m : m*m <= n, primes()):
        if n%d == 0:
            return False
    return True

def modpow(b,p,m):
    result = 1
    while p > 0:
        if p & 1 == 1:
            result = (result * b) % m
        b = (b * b) % m
        p >>= 1
    return result

def MRTest(n,k):
    if n%2 == 0:
        return False
    d = n-1
    s = 0
    while d%2 == 0:
        d //= 2
        s += 1
    for i in range(0,k):
        a = random.randrange(1,n)
        if modpow(a,d,n) == 1:
            continue
        for r in range(0,s):
            if modpow(a,d*2**r,n) == n-1:
                break
        else:
            return False
    return True

def evens():
    i = 2
    while True:
        yield i
        i += 2

sum = 0
k = 5
for n in itertools.takewhile(lambda a:a<150000000, evens()):
    if (n%3 != 0 and
        n%7 != 0 and
        n%13 != 0 and
        MRTest(n*n+1,k) and
        MRTest(n*n+3,k) and
        MRTest(n*n+7,k) and
        MRTest(n*n+9,k) and
        MRTest(n*n+13,k) and
        MRTest(n*n+27,k) and
        (not MRTest(n*n + 15, k)) and
        (not MRTest(n*n + 19, k)) and
        (not MRTest(n*n + 21, k)) and
        (not MRTest(n*n + 25, k))):
        print(n)
        sum += n
print("sum="+str(sum))
