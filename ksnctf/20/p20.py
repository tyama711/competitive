#! /usr/bin/env python

import sympy
import sys

with open('pi.txt', 'r') as f:
    digits = ''
    answer = None
    for line in f:
        digits += line.translate(str.maketrans('', '', '. \n'))
        i = 0
        while len(digits) - i >= 10:
            if digits[i] != '0' and sympy.isprime(int(digits[i:i+10])):
                print('FLAG_Q20_' + str(digits[i:i+10]))
                sys.exit()
            i += 1
        digits = digits[-9:]
