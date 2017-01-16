from sympy.functions.combinatorial.numbers import nC

def p(n):
    ret = sum(map(lambda k:nC(n,k)-1, range(1,n)))
    return ret * nC(26,n)

def main():
    print(max(map(p, range(2,26+1))))

if __name__ == '__main__':
    main()
