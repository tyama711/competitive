import math as mt
import itertools as it
import sys
sys.path.append('/home/yama/ProjectEuler')
import haskell as hs

def f(x):
    return mt.floor(2**(30.403243784 - x**2)) * 10**-9

u0 = -1
un_p = 0
un_pp = 0
for un in hs.iterate(f,u0):
    if un == un_pp:
        print(un + un_p)
        break
    un_pp = un_p
    un_p = un
