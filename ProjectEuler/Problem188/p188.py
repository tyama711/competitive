
def modpow(base, exponent, mod):
    if exponent == 0:
        return 1
    if exponent % 2 == 1:
        return (base * modpow(base, exponent // 2, mod)**2) % mod
    return modpow(base, exponent // 2, mod)**2 % mod

def tetration(a, b, mod):
    if b == 1:
        return a
    return modpow(a, tetration(a, b-1, mod), mod)

print(tetration(1777,1855,10**8))
