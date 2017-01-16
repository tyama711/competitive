import fractions as fr

def solve(n):
    ans = []
    limit = sum(map(lambda x:fr.Fraction(1, x*x), range(2, n+1)))
    def _solve(xs, s, t, i):
        if i > n or limit - t < fr.Fraction(1, 2):
            return
        ys = xs + [i]
        s2 = s + fr.Fraction(1, i*i)
        t2 = t + fr.Fraction(1, i*i)
        if s2 == fr.Fraction(1, 2):
            print(ys)
            ans.append(ys)
        elif s2 < fr.Fraction(1, 2):
            _solve(xs, s, t2, i+1)
            _solve(ys, s2, t, i+1)
        else:
            _solve(xs, s, t2, i+1)
        return
    _solve([], 0, 0, 2)
    return ans
            
print(solve(35))
