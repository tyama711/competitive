import random

def trial():
    env = [1]
    count = 0
    for i in range(16):
        if len(env) == 1:
            count += 1
        a = random.randrange(0,len(env))
        if env[a] == 5:
            del env[a]
        else:
            env.extend(list(range(env[a]+1,6)))
            del env[a]
    return count - 2

sum = 0
n = 100000
for j in range(10):
    for i in range(n):
        sum += trial()
    print(sum)
