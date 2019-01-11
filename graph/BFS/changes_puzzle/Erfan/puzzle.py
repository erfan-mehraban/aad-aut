from collections import deque

def lcs(a, b):
    lengths = [[0 for j in range(len(b)+1)] for i in range(len(a)+1)]
    for i, x in enumerate(a):
        for j, y in enumerate(b):
            if x == y:
                lengths[i+1][j+1] = lengths[i][j] + 1
            else:
                lengths[i+1][j+1] = max(lengths[i+1][j], lengths[i][j+1])
    return lengths[-1][-1]

def check_different_char(a, b):
    f = False
    for i in range(len(a)):
        if a[i] != b[i]:
            if f:
                return False
            f = True
    return True

def can_connect(x, y):
    x=x.lower()
    y=y.lower()
    delta = len(x) - len(y)
    if delta > 1:
        return False
    if delta == 0:
        return check_different_char(x, y)
    if delta == 1 or delta == -1:
        if lcs(x, y) == min(len(x), len(y)):
            return True
        else:
            return False

def bfs(a, s, w):
    q = deque([(s,0)])
    v = [False for _ in range(len(a))]
    v[s] = True
    mutation = [w[s] for _ in range(len(a))]
    while len(q):
        i, d = q.popleft()
        for neighbor in a[i]:
            if not v[neighbor]:
                q.append((neighbor,d+1))
                mutation[neighbor] = mutation[i] + " " + w[neighbor]
                v[neighbor] = True
    return mutation


wc, q = tuple(map(int, input().split()))
wl = input().split()
wd = {}
for i, w in enumerate(wl):
    wd[w] = i

a = [ list() for _ in range(wc)]
for i in range(wc):
    for j in range(i+1, wc):
        if can_connect(wl[i], wl[j]):
            a[i].append(j)
            a[j].append(i)

# for i, x in enumerate(a):
#     print(i, wl[i], x)

mutation_results = [ list() for _ in range(wc) ]
for i in range(wc):
    mutation_results[i] = bfs(a, i ,wl)

# for i, x in enumerate(mutation_results):
#     print(wl[i], x)
for _ in range(q):
    query = input().split()
    if query[0] in wd and query[1] in wd:
        if query[0]==query[1]:
            t = wl[wd[query[0]]]
            print(t+" "+t)
            continue
        m = mutation_results[wd[query[0]]][wd[query[1]]]
        if len(m.split())>1:
            print(m)
        else:
            print("*")
    else:
        print("*")