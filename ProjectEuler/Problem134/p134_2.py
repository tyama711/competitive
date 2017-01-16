import primesieve as ps

def numOfDigits(n):
    ret = 0
    while n > 0:
        ret += 1
        n //= 10
    return ret

# solve ax + by = c
def Diophantos(a,b,c):
    from fractions import gcd
    d = gcd(a,b)
    if c % d != 0:
        return None
    a0, a1 = a, b
    b0, b1 = 1, 0
    c0, c1 = 0, 1
    while a1 != d:
        c0_new, c1_new = b0 - a0//a1*c0, b1 - a0//a1*c1
        a0, a1 = a1, a0 % a1
        b0, b1 = c0, c1
        c0, c1 = c0_new, c1_new
    return (c0 * c // d, c1 * c // d)

ans = 0
n = 10**6
it = ps.Iterator()
it.skipto(3)
p2 = it.next_prime()
while True:
    p1 = p2
    p2 = it.next_prime()
    if p1 > n:
        break
    x, y = Diophantos(10**numOfDigits(p1), p2, -p1)
    ans += x % p2 * 10**numOfDigits(p1) + p1

print(ans)
