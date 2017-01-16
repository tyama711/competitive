#! /usr/bin/env sage

from sage.all import *

var('x')
gen = expand((1 + x + x**2/2 + x**3/6)**10)
print(gen.coefficient(x, 18) * factorial(18) * 9 / 10)
