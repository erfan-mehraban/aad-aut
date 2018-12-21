from collections import deque
def min_path(a, b):
    if b == -1:
        return a
    return min(a, b)

n, m, k = list(map(int,input().split()))
hospitals = list(map(int, input().split()))
g = [hospitals] + [ list() for _ in range(n) ]
dis = [-1] * (n+1)
for _ in range(m):
    x,y = list(map(int, input().split()))
    g[x].append(y)
    g[y].append(x)

# print("counter, current, adj, deq")
d = deque([(0, -2)])
while len(d)>0:
    u, pd = d.popleft()
    dis[u] = min_path(pd+1, dis[u])
    # print(pd, u, g[u], d)
    for adj_v in g[u]:
        if dis[adj_v] == -1:
            d.append((adj_v, pd+1))
# print(dis)
for x in dis[1:]:
    print(x)
