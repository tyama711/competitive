import solve
# import primesieve as ps
# import numpy as np

# def mostDigit(n):
# #    d = np.zeros(10, dtype=np.intc)
#     d = [[i,0] for i in range(10)]
#     while n > 0:
# #        d[n%10] += 1
#         d[n%10][1] += 1
#         n //= 10
# #    return (np.argmax(d), np.max(d))
#     return max(d, key=lambda x:x[1])

# def solve(n):
#     it = ps.Iterator()
#     it.skipto(10**(n-1))

# #    S = np.zeros([10,10], dtype=np.uint64)
#     S = [[0 for _ in range(10)] for _ in range(10)]
#     p = it.next_prime()
#     while p < 10**n:
#         d, m = mostDigit(p)
#         if m > n//2:
#             S[d][m] += p
#         p = it.next_prime()
#     ans = 0
#     for d in range(10):
#         for j in range(9, -1, -1):
#             if S[d][j] != 0:
#                 ans += S[d][j]
#                 break
#     print(ans)

solve.solve(10)
