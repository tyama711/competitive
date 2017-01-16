
def combi(n, m):
    if m == 0:
        return 1
    import functools as ft
    import operator as op
    ret = ft.reduce(op.mul, range(n-m+1, n+1))
    ret //= ft.reduce(op.mul, range(1, m+1))
    return ret

n = 100
d = 10
for i in range(n):
    print(i, end='')
    for j in range(i+1):
        if combi(i,j) % d == 0:
            print('*', end='')
        else:
            print(' ', end='')
    print('\n', end='')
