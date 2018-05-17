from functools import lru_cache as cache
import sys
sys.setrecursionlimit(100000)

@cache(maxsize = None)
def combi(n, m, mod):
    if m == 0 or m == n:
        return 1
    if m > n-m:
        return combi(n, n-m, mod)
    else:
        return (combi(n-1, m-1, mod) + combi(n-1, m, mod)) % mod

ans = 0
h, w, a, b = tuple(map(int, input().split(' ')))
for _a in range(0, h-a):
    if h-a + b - _a > w:
        continue
    else:
        ans += combi(h-a+b-1, _a, 10**9 + 7) * combi(w+a-b-1, h-_a-1, 10**9 + 7)
        ans %= 10**9 + 7

print(ans)
