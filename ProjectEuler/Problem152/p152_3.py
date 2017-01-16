import fractions as fr
from collections import deque

def solve(n):
    ans = []
    c = sum(map(lambda x:1/x**2, range(2,n+1)))
    xs = deque([2], maxlen=n)
    def _solve(a, b, m):
        if abs(a - 0.5) < 0.00000000001:
            ans.append(list(xs))
            return None
        elif b > c - 0.5 or a > 0.5 - 1/(n+1)**2 or m > n:
            return None
        else:
            xs.append(m)
            _solve(a + 1/m**2, b, m+1)
            xs.pop()
            _solve(a, b + 1/m**2, m+1)
            return None
    _solve(0.25, 0, 3)
    return ans

print(solve(35))
