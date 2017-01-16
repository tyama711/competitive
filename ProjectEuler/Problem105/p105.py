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

with open('p105_sets.txt', 'r') as file:
    s = 0
    for line in file:
        xs = list(map(int, line.split(',')))
        if test(xs):
            s += sum(xs)
print(s)
