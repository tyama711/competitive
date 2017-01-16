import sys

n = 1000
t = 0
ans = sys.maxsize
data = [[]]
for i in range(1,n+1):
    xs = [0 for _ in range(i+1)]
    for j in range(1,i+1):
        t = (615949*t + 797807) & (2**20-1)
        xs[j] = xs[j-1] + t - 2**19
    data.append(xs[:])

for i in range(1,n+1):
    for j in range(1,i+1):
        mn = sys.maxsize
        v = 0
        for k in range(n-i):
            v += data[i+k][j+k] - data[i+k][j-1]
            if v < mn:
                mn = v
        if mn < ans:
            ans = mn
print(ans)
