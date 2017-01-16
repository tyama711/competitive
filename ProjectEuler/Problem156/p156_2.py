import math
import numpy as np

def numOfDigits(n,base=10):
    return int(math.log(n,base)) + 1

def countDigits(n,d):
    if n == 0:
        return 0
    count = 0
    for i in range(numOfDigits(n)):
        a = 10**i
        count += n // (10*a) * a + min(max(0, n % (10*a) - d*a + 1), a)
    return count

def solve(d, lower, upper):
    ans = []
    l = 0
    u = lower
    if upper - lower <= 100:
        for i in range(lower, upper):
            if i == countDigits(i, d):
                ans.append(i)
        return ans
    for i in range(1, 11):
        l = u
        u += (upper - lower) // 10
        c1 = countDigits(l, d)
        c2 = countDigits(u, d)
        if (c1 <= l+100 and c2 >= u-100) or \
            (c1 >= l-100 and c2 <= u+100):
            ans += solve(d, l, u)
    return ans
        
print(sum(map(lambda d:sum(solve(d, 0, 1000000000000)), range(1,10))))
