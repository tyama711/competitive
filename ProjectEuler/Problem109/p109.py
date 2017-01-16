import itertools as it

singles = list(map(lambda x:(x,1), range(1,21))) + [(25,1)]
doubles = list(map(lambda x:(x,2), range(2,41,2))) + [(50,2)]
triples = list(map(lambda x:(x,3), range(3,61,3)))
areas = sorted(singles + doubles + triples)

count = len(doubles)

for a in areas:
    for b in doubles:
        if a[0] + b[0] < 100:
            count += 1
    for c in it.dropwhile(lambda x:x < a, areas):
        for d in doubles:
            if a[0] + c[0] + d[0] < 100:
                count += 1

print(count)
