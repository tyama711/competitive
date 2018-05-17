def iterate(f,x,recursion = 0):
    if recursion == 0:
        while True:
            yield x
            x = f(x)
    else:
        for _ in range(recursion + 1):
            yield x
            x = f(x)

def mapAccumL(f, acc, xs):
    ys = []
    for x in xs:
        (acc, y) = f(acc, x)
        ys.append(y)
    return (acc, ys)

def unfoldl(f, init, finish):
    acc = init
    while not finish(acc):
        acc, y = f(acc)
        yield y
