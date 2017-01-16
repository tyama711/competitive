import itertools as it

n = 1000000
ans = 0
for i in it.takewhile(lambda a:a*a <= n // 4, it.count(1)):
    ans += max(0, (n // 4) // i - i)

print(ans)
