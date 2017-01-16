from fractions import Fraction

subunits=[set() for i in range(18)]
subunits[0].add(Fraction(1,1))

def solve(n):
    for i in range(1,n):
        for j in range(0,n//2):
            for a in subunits[j]:
                for b in subunits[i-j-1]:
                    subunits[i].add(a+b)
                    subunits[i].add(1 / (1/a + 1/b))
        for j in range(0,i):
            subunits[i] = subunits[i].difference(subunits[j])

solve(18)
print(sum(map(len,subunits)))
