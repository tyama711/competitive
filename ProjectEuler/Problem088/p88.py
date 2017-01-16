from itertools import combinations_with_replacement, groupby
from functools import reduce
from operator import mul
from math import log2

def candidates(n):
    m = int(log2(n)) + 1
    for k in range(2,m+1):
        xs = [2 for _ in range(k)]
        p = reduce(mul, xs)
        while p <= 2*n:
            yield xs[:]
            for i in range(len(xs)):
                b = xs[i] + 1
                for j in range(i+1):
                    xs[j] = b
                p = reduce(mul, xs)
                if p <= 2*n:
                    break

product_sum = [0,0] + [24000 for _ in range(2,12001)]

for xs in candidates(12000):
    p = reduce(mul, xs)
    k = len(xs) + p - sum(xs)
    if k <= 12000 and p < product_sum[k]:
        product_sum[k] = p

print(sum(map(lambda t:t[0], groupby(sorted(product_sum)))))
