#! /usr/bin/env python

with open('number', 'r') as f:
    x = f.read()

cand = [set()]
for i in range(1,10,2):
    if (i**101) % 10 == int(x[-1:]):
        cand[0].add(i)

i = 1
while True:
    cand.append(set())
    for n in cand[i-1]:
        for j in range(10):
            if (j * 10**i + n)**101 % 10**(i+1) == int(x[-i-1:]):
                cand[i].add(j * 10**i + n)
    for n in cand[i]:
        if n**101 == int(x):
            ans = n
            break
    else:
        i += 1
        continue
    break

print(ans)
