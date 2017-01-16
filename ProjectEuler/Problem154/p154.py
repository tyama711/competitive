import math
from itertools import takewhile

def comb(n,m):
    return math.factorial(n) // (math.factorial(m) * math.factorial(n-m))

def layer(n):
    ls = []
    for a in range(n,-1,-1):
        ls.append([comb(n,a)*comb(n-a,b) for b in range(0,n-a+1)])
    return ls

def iterate(f,x):
    while True:
        yield x
        x = f(x)

cache = {}
def zerosOfFact(n):
    if n in cache:
        return cache[n]
    a = sum([x for x in takewhile(lambda x:x>0, iterate(lambda x:x//5, n))]) - n
    cache[n] = a
    return a

n = 2000
zn = zerosOfFact(n)
count = 0
for a in range(n,-1,-1):
    za = zerosOfFact(a)
    for b in range(n-a+1):
        if zn - za - zerosOfFact(b) - zerosOfFact(n-a-b) > 12:
            count += 1
print(count)

# d = 1000000
# for line in layer(200):
#     for a in line:
#         if a % d == 0:
#             print('*', end='')
#         else:
#             print('-', end='')
#     print('')
