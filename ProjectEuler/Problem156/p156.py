import math
import numpy as np

def numOfDigits(n,base=10):
    return int(math.log(n,base)) + 1

def countDigits(n,d):
    if n == 0:
        return 0
    count = 0
    for i in range(numOfDigits(n)):
        a = 10**i
        count += n // (10*a) * a + min(max(0, n % (10*a) - d*a + 1), a)
    return count

def countDigits2(n,d):
    return n // 100 * 10 + min(max(0, n%100 - 10*d + 1), 10)


print(countDigits(2200000000,2))
# unit = 1000000
# d = 2
# ans = 0
# for i in range(2200, 2300):
#     arr = np.arange(i*unit, (i+1)*unit)
#     brr = np.zeros(unit, dtype=np.int64)
#     crr = np.arange(i*unit, (i+1)*unit)
#     for i in range(numOfDigits((i+1)*unit)):
#         crr = arr % (10**(i+1)) - d*10**i + 1
#         crr[crr < 0] = 0
#         crr[crr > 10**i] = 10**i
#         brr += arr / (10**(i+1)) * 10**i + crr

#     if np.any(arr==brr):
#         print(arr[arr==brr])
#         ans += np.sum(arr[arr==brr])
# print(ans)
    
#print(brr[0:100])

# for n in range(100):
#     print("{0:2d}:".format(n), end = ' ')
#     for d in range(1,10):
#         print("{0:2d}".format(countDigits(n,d)), end = ' ')
#     print('')
