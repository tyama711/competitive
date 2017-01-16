import primesieve as ps
import math as mt

def numOfDigits(n):
    return mt.floor(mt.log10(n)) + 1

def func(p1, p2):
    i = 1
    a = 10**(numOfDigits(p1))
    b = a + p1
    while True:
        if b % p2 == 0:
            return b
        b += a

it = ps.Iterator()
it.next_prime()
p1 = it.next_prime()
p2 = it.next_prime()
ans = 0
while p1 <= 10**6:
    ans += func(p1,p2)
    p1 = p2
    p2 = it.next_prime()
print(ans)
