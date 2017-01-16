import sys

length = [[sys.maxsize for i in range(6400)] for j in range(6400)]
lefts = {}

for i in range(80):
    s = [int(x) for x in input().split(",")]
    for j in range(80):
        if j == 0:
            lefts[80*i] = s[0]
        else:
            length[80*i+j-1][80*i+j] = s[j]
        if i != 0 and j != 0 and j != 79:
            length[80*(i-1)+j][80*i+j] = s[j]
        if i != 79 and j != 0 and j != 79:
            length[80*(i+1)+j][80*i+j] = s[j]

def dijkstra(start, goal):
    Q = set([i for i in range(6400)])
    dist = [sys.maxsize for i in range(6400)]
    dist[start] = 0
    prev = [-1 for i in range(6400)]
    while goal.issubset(Q):
        u = dist.index(min(dist))
        ans = dist[u]
        Q.remove(u)
        for v in Q:
            if dist[v] > dist[u] + length[u][v] :
                dist[v] = dist[u] + length[u][v]
                prev[v] = u
        dist[u] = sys.maxsize
    return ans

minimum = sys.maxsize
for i in range(80):
    a = dijkstra(80*i, set([80*j+79 for j in range(80)])) + lefts[80*i]
    if a < minimum:
        minimum = a
print(minimum)
