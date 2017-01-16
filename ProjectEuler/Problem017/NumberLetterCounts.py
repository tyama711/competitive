a = ["one", "two", "three", "four", "five", "six", "seven",
     "eight", "nine", "ten", "eleven", "twelve", "thirteen",
     "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
     "nineteen"]

b = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy",
     "eighty", "ninety"]

def n2s(n):
    ret = ""
    if n == 1000:
        return "onethousand"
    if n % 100 == 0:
        ret = a[n // 100 - 1]
        ret += "hundred"
        return ret
    if n > 100:
        ret += a[n // 100 - 1]
        ret += "hundredand"
        n %= 100
    if n >= 20:
        ret += b[n // 10 - 2]
        n %= 10
    if n > 0:
        ret += a[n-1]
    return ret

i = 1
ans = 0
while i <= 1000:
    ans += len(n2s(i))
    i += 1
print(ans)
