import math
import fractions as fr

def D(n):
    k = max((math.floor(n / math.e), math.ceil(n / math.e)), key = lambda a:a * math.log(n / a))
    while k % 2 == 0:
        k //= 2
    while k % 5 == 0:
        k //= 5
    k //= fr.gcd(n,k)
    if k == 1:
        return -n
    return n

print(sum(map(D,range(5,10001))))
