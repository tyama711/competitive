def reverseNum(n):
    return int(str(n)[::-1])

def isReversible(n):
    if n % 10 == 0:
        return False
    m = n + reverseNum(n)
    while m:
        if m % 2 == 0:
            return False
        m //= 10
    return True

count = 0
for i in range(1,1000001):
    if isReversible(i):
        count += 1
print(count)
