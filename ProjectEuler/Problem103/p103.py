import itertools as it
import sys

#cand = {20, 31, 38, 39, 40, 42, 45}

def test(cand):
    for i in range(1, len(cand)//2 + 1):
        for j in range(i, len(cand)+1-i):
            for a in it.combinations(cand, i):
                for b in it.combinations(set(cand).difference(set(a)), j):
                    if sum(a) == sum(b) or (j > i and sum(a) >= sum(b)):
                        return False
    return True

def solve():
    n = 7
    ans = 255
    for s in it.count(161):
        print(s)
        xs = []
        for a in range(20, s//7):
            xs.append(a)
            for b in range(a+1, (s-sum(xs))//6):
                xs.append(b)
                for c in range(b+1, (s-sum(xs))//5):
                    if not test(xs + [c]):
                        continue
                    xs.append(c)
                    for d in range(c+1, (s-sum(xs))//4):
                        if not test(xs + [d]):
                            continue                        
                        xs.append(d)
                        for e in range(d+1, (s-sum(xs))//3+1):
                            if not test(xs + [e]):
                                continue
                            xs.append(e)
                            for f in range(e+1, (s-sum(xs))//2+1):
                                if not test(xs + [f]):
                                    continue
                                xs.append(f)
                                for g in range(f+1, s-sum(xs)+1):
                                    if test(xs + [g]):
                                        return xs + [g]
                                xs.pop()
                            xs.pop()
                        xs.pop()
                    xs.pop()
                xs.pop()
            xs.pop()

print(solve())
