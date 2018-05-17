from copy import copy

def main():
    n, m = (int(s) for s in input().strip().split(' '))
    paths = dict()
    for i in range(1, m+1):
        a, b = (int(s) for s in input().strip().split(' '))
        paths[i] = (a,b)
    q = int(input().strip())
    for i in range(q):
        x, y, z = (int(s) for s in input().strip().split(' '))
        score = 0
        visited = set((x, y))
        paths2 = {k:v for k,v in paths.items() if not (v[0] in visited and v[1] in visited)}
        for _ in range(z-2):
            for j in range(1,m+1):
                if j in paths2.keys() and visited.intersection(paths2[j]) != set():
                    if j > score:
                        score = j
                    visited.update(paths2[j])
                    paths2 = {k:v for k,v in paths2.items() if not (v[0] in visited and v[1] in visited)}
                    break
        print(score)

main()
