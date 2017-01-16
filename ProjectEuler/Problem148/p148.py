import math

# def comb(n,p):
#     return (math.factorial(n) // math.factorial(p) // math.factorial(n-p))

# for i in range(0,201):
#     print(str(i)+"\t:", end="")
#     for j in range(0,i+1):
#         if comb(i,j)%7 == 0:
#             print("*", end="")
#         else:
#             print(" ", end="")
#     print("")

a = 33531600616 # 1000000000(10) = 33531600616(7)
b = []
while a:
    b.append(a%10)
    a //= 10
ans = 0
for k in range(0,len(b)):
    p = 1
    for j in range(k+1,len(b)):
        p *= b[j] + 1
    ans += p*b[k]*(b[k]+1)*28**k // 2
print(ans)
