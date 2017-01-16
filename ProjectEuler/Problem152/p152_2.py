import fractions as fr

def solve(n):
    cache = {}
    ans = []
    limit = sum(map(lambda x:fr.Fraction(1, x*x), range(2, n+1)))
    def _solve(x, t, i):
        if x == 0:
            return 1
        if i > n or limit - t < fr.Fraction(1, 2):
            return 0
        if not x in cache:
            x2 = x - fr.Fraction(1, i*i)
            t2 = t + fr.Fraction(1, i*i)
            cache[x] = _solve(x2, t, i+1) + _solve(x, t2, i+1)
        return cache[x]
    return _solve(fr.Fraction(1,2), 0, 2)
            
print(solve(35))
