import math

def countDigits(n,d):
    if n == 0:
        return 0
    count = 0
    for i in range(numOfDigits(n)):
        a = 10**i
        count += n // (10*a) * 10**i + min(max(0, n % (10*a) - d*a + 1), a)
    return count

def numOfDigits(n,base=10):
    return int(math.log(n,base)) + 1

def solve(d):
    ans = []
    n = 10**11
    while n >= 0:
        c = countDigits(n,d)
        if c == n:
            ans.append(n)
            n -= 1
        elif c < n:
            n = c
        else:
            n -= (c - n) // numOfDigits(n) + 1
    return sum(ans)

print(sum(map(lambda d:solve(d), range(1,10))))
