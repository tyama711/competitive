import sys

length = [[sys.maxsize for i in range(6400)] for j in range(6400)]
Q = set([i for i in range(6400)])
dist = [sys.maxsize for i in range(6400)]
dist[0] = 0
prev = [-1 for i in range(6400)]

for i in range(80):
    s = [int(x) for x in input().split(",")]
    if i == 0:
        start = s[0]
    for j in range(80):
        if j != 0:
            length[80*i+j-1][80*i+j] = s[j]
        if i != 0:
            length[80*(i-1)+j][80*i+j] = s[j]

ans = {}
while 6399 in Q:
    u = dist.index(min(dist))
    ans[u] = dist[u]
    Q.remove(u)
    for v in Q:
        if dist[v] > dist[u] + length[u][v] :
            dist[v] = dist[u] + length[u][v]
            prev[v] = u
    dist[u] = sys.maxsize

print(ans[6399]+start)
