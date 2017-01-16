count = 0
n = 200000
j = 0
cache = [-1 for _ in range(n//2 + 1)]

def countFactor(_n, factor):
    if _n <= n//2 and cache[_n] != -1:
        return cache[_n]
    _count = 0
    _m = _n
    while _m > 0:
        _m //= factor
        _count += _m
    if _n <= n//2:
        cache[_n] = _count
    return _count

a = countFactor(n, 5)
for i in range(n//3 + 1):
    for j in range(i):
        if 12 <= a \
           - countFactor(i, 5) \
           - countFactor(j, 5) \
           - countFactor(n-i-j, 5):
            count += 6
    if 12 <= a \
       - 2*countFactor(i, 5) \
       - countFactor(n - 2*i, 5):
        count += 3

for i in range(n//3+1, n//2+1):
    if 12 <= a \
       - 2*countFactor(i, 5) \
       - countFactor(n-2*i, 5):
        count += 3
    for j in range(n-2*i-1, -1, -1):
        if 12 <= a \
           - countFactor(i, 5) \
           - countFactor(j, 5) \
           - countFactor(n-i-j, 5):
            count += 6

# #    if j != 0:
# #        print('{0}:{1}'.format(i, j))
#     if 12 <= countFactor(n, 5) \
#            - countFactor(i, 5) \
#            - countFactor(j, 5) \
#            - countFactor(n-i-j, 5):
#         a = True
#         j -= 1
#     else:
#         a = False
#         j += 1
#     b = a
#     while a == b and j >= 0 and j <= i and j <= n-2*i:
#         if 12 <= countFactor(n, 5) \
#                - countFactor(i, 5) \
#                - countFactor(j, 5) \
#                - countFactor(n-i-j, 5):
#             b = True
#             j -= 1
#         else:
#             b = False
#             j += 1
#     if b == True:
#         j += 1
# #    print('i={0},j={1},a={2}'.format(i, j, a))
#     if j >= 0 and j <= i and j <= n-2*i:
#         count += min(i-j, n-2*i-j) * 6 + 3
#     elif j < 0:
#         j = 0
#     else:
#         j = min(i, n-2*i)

print(count)
