import primesieve as ps
import itertools as it
import math as mt

n = 10**8
primes = ps.generate_primes(mt.floor(mt.sqrt(n)))

count = 0
for i in range(0,len(primes)):
    count += ps.count_primes((n-1) // primes[i]) - i

print(count)
