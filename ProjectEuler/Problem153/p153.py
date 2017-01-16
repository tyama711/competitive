import math as m
import fractions as f

def lattice(r):
    x = 2
    y = 1
    while y**2 < r:
        while x**2 + y**2 <= r:
            yield((x,y))
            x += 1
        y += 1
        x = y+1

N = 10**8
sum = 0

v = m.floor(m.sqrt(N))
sum += v * (v + 1) // 2
for x in range(1, v+1):
    sum += x * (N//x - x) + ((N//x + x + 1) * (N//x - x) // 2)

v = m.floor(m.sqrt(N//2))
sum += v * (v + 1)
for i in range(1, v + 1):
    sum += (2 * i + (N//(2*i) + i + 1)) * (N//(2*i) - i)

for (x,y) in lattice(N):
    if (f.gcd(x,y) != 1):
        continue
    v = m.floor(m.sqrt(N//(x**2+y**2)))
    sum += (x+y) * v * (v + 1)
    for i in range(1, v + 1):
        sum += (2 * i + (N // (i * (x**2 + y**2)) + i + 1)) * \
               (x+y) * (N // (i*(x**2+y**2)) - i)

print(sum)
