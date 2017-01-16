#! /home/yama/Downloads/sage-6.4.1/sage -python

from sage.all import sum, var, factorial

var('i,j')
print(sum((i+2)**2*(i+1)*sum(3**j*factorial(i)/factorial(i-j)*13**(i-j), j, 0, i), i, 0, 13))

