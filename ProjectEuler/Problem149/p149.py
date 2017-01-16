def compose(outer_func, inner_func):
    def composed(*args, **kwds):
        return outer_func(inner_func(*args, **kwds))
    return composed

def getMaxSum(xs):
    s = sum(xs)
    mx = s
    tmp = [0 for i in range(0,len(xs))]
    for j in range(len(xs)-1,-1,-1):
        tmp[j] = mx
        s -= xs[j]
        if s > mx:
            mx = s
    s = 0
    mn = 0
    mx = 0
    for j in range(0,len(xs)):
        if tmp[j] - mn > mx:
            mx = tmp[j] - mn
        s += xs[j]
        if s < mn:
            mn = s
    return mx

def transpose(xs):
    return list(map(list,zip(*xs)))

def getDiagonal(xs,n):
    ys = []
    if n >= len(xs):
        i = len(xs)-1
        j = n - len(xs) + 1
    else:
        i = n
        j = 0
    while j < len(xs[0]) and i >= 0:
        ys.append(xs[i][j])
        i -= 1
        j += 1
    return ys
    
table = [[0 for i in range(0,2000)] for j in range(0,2000)]

for k in range(1,56):
    table[0][k-1] = (100003 - 200003*k + 300007*k**3) % 1000000 - 500000
for k in range(56,4000001):
    table[(k-1)//2000][(k-1)%2000] = \
    (table[(k-25)//2000][(k-25)%2000] + table[(k-56)//2000][(k-56)%2000]
     + 1000000) % 1000000 - 500000

table2 = transpose(table)
table3 = list(map(compose(list,reversed), table))

maxsum = 0
for i in range(0,2000):
    mx = getMaxSum(table[i])
    if mx > maxsum:
        maxsum = mx
for i in range(0,2000):
    mx = getMaxSum(table2[i])
    if mx > maxsum:
        maxsum = mx
for i in range(0,3999):
    mx = getMaxSum(getDiagonal(table,i))
    if mx > maxsum:
        maxsum = mx
for i in range(0,3999):
    mx = getMaxSum(getDiagonal(table3,i))
    if mx > maxsum:
        maxsum = mx
print(maxsum)
