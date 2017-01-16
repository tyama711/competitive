import math
def solve(a, b, prev_x, count):
    d = math.sqrt(100*(a*a + 4) - 4*b*b)
    x1 = (-a*b + d) / (a*a + 4)
    x2 = (-a*b - d) / (a*a + 4)
    if abs(prev_x-x1) > abs(prev_x-x2):
        x = x1
    else:
        x = x2
    y = a*x + b
    if -0.01 <= x and x <= 0.01 and y > 0.0:
        return count
    m = -4*x/y
    next_a = 2*m*(1+a*a) / (-m*m+2*a*m+1) - a
    next_b = -next_a*x + y
    return solve(next_a, next_b, x, count+1)

print(solve(-19.7/1.4, 10.1, 0.0, 0))
