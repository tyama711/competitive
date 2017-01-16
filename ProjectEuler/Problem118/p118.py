import sympy as sp
import itertools as it

def str_diff(s1, s2):
    return ''.join([c for c in s1 if c not in s2])

def numOfDigits(n):
    if n <= 0:
        return 0
    count = 0
    while n > 0:
        count += 1
        n //= 10
    return count

def solve(digits, min):
    count = 0
    for i in range(numOfDigits(min), len(digits)//2 + 1):
        for cand in map(''.join, it.permutations(digits, i)):
            if int(cand) < min or not sp.isprime(int(cand)):
                continue
            count += solve(str_diff(digits, cand), int(cand))
    for cand in map(''.join, it.permutations(digits)):
        if int(cand) >= min and sp.isprime(int(cand)):
            count += 1
    return count

print(solve('123456789',2))
