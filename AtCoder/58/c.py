from functools import reduce
import operator as op
from haskell import unfoldl

n = int(input().split(' ')[0])
ds_str = input().split(' ')
ds = set(map(int, ds_str))

for m in range(n, 100000):
    mlist = list(unfoldl(lambda acc: (acc//10, acc%10), m, lambda acc: acc == 0))
    if reduce(op.or_, map(lambda x:x in ds, mlist)):
        continue
    else:
        print(m)
        break
