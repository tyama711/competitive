
cache = [[] for _ in range(201)]
m = [0 for _ in range(201)]
cache[1].append([False for _ in range(201)])
cache[1][-1][1] = True
m[1] = 0

for i in range(2,201):
    mn = 1000
    for j in range(1,i):
        for xs in cache[j]:
            if xs[i-j] == True and m[j] + 1 < mn:
                mn = m[j] + 1
                cache[i].clear()
                cache[i].append(xs[:])
                cache[i][-1][i] = True
            elif xs[i-j] == True and m[j] + 1 == mn:
                cache[i].append(xs[:])
                cache[i][-1][i] = True
    m[i] = mn

print(sum(m))
