#! /usr/bin/env sage
from sage.all import *

ans = 0
n = 10**8
perimeter = 12

a = expand((sqrt(2)+1)**5)
b = expand((sqrt(2)-1)**5)
while perimeter <= n:
    ans += n // perimeter
    perimeter = int(expand(
        (a + b + sqrt(2)*(a - b)) / (2*sqrt(2))
    ))
    a = expand(a*(sqrt(2)+1)**2)
    b = expand(b*(sqrt(2)-1)**2)

print(ans)
