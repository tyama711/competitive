import itertools as it

n = 1000000
xs = [0 for i in range(0,n//4)]
for i in it.takewhile(lambda a:a*a <= n // 4, it.count(1)):
    for j in it.takewhile(lambda a:a*i <= n // 4, it.count(i+1)):
        xs[i*j-1] += 1

ans = sum([1 for _ in filter(lambda a:1 <= a <= 10, xs)])
print(ans)
