def f(n,m):
    if n <= 0 or m <= 0:
        return 0
    elif n == m == 1 or abs(n-m) >= 2:
        return 1
    elif n == m:
        return 6*(n-1)
    else:
        return max(n,m)

def g(n,m):
    ret = 0
    for i in range(1,n+1):
        for j in range(1,m+1):
            ret += i*j*f(n+1-i,m+1-j)
    return ret

def h(n,m):
    ret = 0
    for i in range(1,n+1):
        for j in range(1,m+1):
            ret += g(i,j)
    return ret

print(h(47,43))
