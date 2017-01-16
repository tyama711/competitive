import primesieve as ps
import itertools as it

def is_prime(n):
    if n < 2:
        return False
    return ps.generate_primes(n)[-1] == n

candidates=['***109', '*2*3*3', '*2*3*3', '*4*6*9',
            '***857', '*4*6*9', '***857']

for c in candidates:
    for i in range(0,10):
        a = int(c.translate(str.maketrans('*',str(i))))
        if is_prime(a):
            print(a)
            break
            
