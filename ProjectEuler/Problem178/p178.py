
def isPandigital(n):
    return set(str(n)) == set('0123456789')

def solve(n):
    count = 0
    def _solve(x, d, m):
        nonlocal count
        if m == 0:
            if isPandigital(x):
                count += 1
        else:
            if d == 0:
                _solve(10*x + 1, 1, m-1)
            elif d == 9:
                _solve(10*x + 8, 8, m-1)
            else:
                _solve(10*x + d-1, d-1, m-1)
                _solve(10*x + d+1, d+1, m-1)
    for i in range(1, 10):
        _solve(i, i, n-1)
    return count

for i in range(10, 25):
    print('i=' + str(i) + ', ' + str(solve(i)))
        
