import primesieve as ps
import itertools as it

def is_prime(n):
    if n < 2:
        return False
    return ps.generate_primes(n)[-1] == n

def check(string):
    return sum([1 for _ in filter(lambda a:is_prime(int(string.translate(str.maketrans('*',str(a))))), range(0,10))])

cands = []
for i in range(10,100):
    for a in map(lambda a:a[0], it.groupby(sorted(it.permutations(list(str(i)+'***'), 5)))):
        for b in [1,3,7,9]:
            if (i*10 + b) % 3 == 0:
                continue
            s = str.join('', a)+str(b)
            if check(s) > 7:
                cands.append(s)

cands2 = []
for c in cands:
    for i in range(0,10):
        a = int(c.translate(str.maketrans('*',str(i))))
        if is_prime(a):
            cands2.append(a)
            break

ans = 10000000
for a in cands2:
    if 10**5 <= a < ans:
        ans = a

print(ans)
