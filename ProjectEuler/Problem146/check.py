import random

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

sum = 0
for i in range(0,13):
    a = int(input())
    if ((not MRTest(a*a + 15, 10)) and
        (not MRTest(a*a + 19, 10)) and
        (not MRTest(a*a + 21, 10)) and
        (not MRTest(a*a + 25, 10))):
        print(a)
        sum += a
print("sum="+str(sum))
