import itertools as it
import operator as op
import sys

mx = 0
for xs in it.combinations(range(1,10), 4):
    vars = [False for _ in range(0, 100)]
    for ys in it.permutations(xs, 4):
        for zs in it.product([op.mul, op.truediv, op.add, op.sub], repeat=3):
            b = zs[2](zs[1](zs[0](ys[0], ys[1]), ys[2]), ys[3])
            c = zs[1](zs[0](ys[0], ys[1]), zs[2](ys[2], ys[3]))
            if b % 1.0 == 0.0 and 0 <= b < 100:
                vars[int(b)] = True
            if c % 1.0 == 0.0 and 0 <= c < 100:
                vars[int(c)] = True
    a = sum([1 for _ in it.takewhile(op.truth, vars[1:])])
    if a > mx:
        mx = a
        ans = xs
print(mx)
print(ans)
