from itertools import groupby, permutations
from math import sqrt

def isSquare(n):
    return n == (int(sqrt(n)))**2

candidates = []
for k, g in groupby(sorted(map(lambda s:s.strip('"'), input().split(',')), key=sorted), key=sorted):
    group = list(g)[:]
    if len(group) != 1:
        candidates.append(group)

for k, xs in groupby(sorted(candidates, key=lambda x:len(x[0]), reverse=True),
                     lambda x:len(x[0])):
    mx = 0
    for x in xs:
        y = ''.join(list(set(x[0])))
        for z in permutations('0123456789', len(y)):
            a = x[0].translate(str.maketrans(y, ''.join(z)))
            b = x[1].translate(str.maketrans(y, ''.join(z)))
            if isSquare(int(a)) and \
               isSquare(int(b)) and \
               a[0] != '0' and \
               b[0] != '0' and \
               max(int(a), int(b)) > mx:
                mx = max(int(a), int(b))
    if mx != 0:
        print(mx)
        break
#    max = 0
#    for x in xs:
        
