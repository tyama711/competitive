import itertools as it

tmp = [[0 for _ in range(0,3)]
       for _ in range(0,2)]

def solve(n, a, l):
    if n == 0:
        tmp[l][a] += 1
        return 1
    count = 0
    if a != 2:
        count += solve(n-1, a+1, l)
    if l != 1:
        count += solve(n-1, 0, l+1)
    return count + solve(n-1, 0, l)

solve(15,0,0)
ans = 0
for l in range(0,2):
    for m in range(0,2-l):
        for a in range(0,3):
            for b in range(0,3-a):
                ans += tmp[l][a]*tmp[m][b]

print(ans)
