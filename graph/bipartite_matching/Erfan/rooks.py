def can_choose(u, graph, visited, match_result):
    for v in graph[u]:
        if not visited[v]:
            visited[v] = True
            if match_result[v] == -1 or can_choose(match_result[v], graph, visited, match_result):
                match_result[v] = u
                return True
    return False

def count_matching(graph, job_size):
    mr_list = [-1] * job_size
    c = 0
    for u in range(len(graph)):
        visited_list = [False] * job_size
        if can_choose(u, graph, visited_list, mr_list):
            c += 1
    return c

n, m = list(map(int, input().split()))
board_obstacle = [list() for _ in range(n)]
for i in range(n):
    board_obstacle[i] = list(map(lambda x: False if x=="." else True, input().strip()))

# for x in board_obstacle:
#     print(x)

board_row_part = [[-1 for _ in range(m)] for _ in range(n)]
r_part = -1
for i in range(n):
    on_obs = True
    r_part += 1
    for j in range(m):
        if board_obstacle[i][j]:
            if not on_obs:
                r_part += 1
                on_obs = True
        else:
            board_row_part[i][j] = r_part
            on_obs = False

# for x in board_row_part:
#     print(x)
# print()

graph = [list() for _ in range(r_part+1)]
c_part = 0
for j in range(m):
    on_obs = True
    c_part += 1
    for i in range(n):
        if board_obstacle[i][j]:
            if not on_obs:
                c_part += 1
                on_obs = True
        else:
            graph[board_row_part[i][j]].append(c_part)
            on_obs = False

# for x in graph:
#     print(x)

print(count_matching(graph, c_part+1))