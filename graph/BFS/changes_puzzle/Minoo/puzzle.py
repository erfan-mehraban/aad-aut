from collections import defaultdict


class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def make(self, words):
        for w in words:
            word = w.lower()
            for ow in words:
                other_word = ow.lower()
                if string_check(word, other_word):
                    self.add_edge(w, ow)

    def find_shortest_path(self, start, end):
        first = start
        visited = defaultdict(str)
        parent = defaultdict(str)

        for i in self.graph:
            visited[i] = False
            parent[i] = None

        queue = []
        queue.append(start)
        visited[start] = True

        while queue:
            start = queue.pop(0)
            if start == end:
                break
            for i in self.graph[start]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
                    parent[i] = start
        if not start == end:
            return []
        path = []
        node = end
        while not node == first:
            path.append(node)
            node = parent[node]
        path.append(first)
        path = path[::-1]
        return path




def string_check(x, y):
    delta = len(x) - len(y)
    if delta > 1:
        return False
    if delta == 0:
        return check_different_char(x, y, len(x))
    if delta == 1 or delta == -1:
        if lcs(x, y, len(x), len(y)) == min(len(x), len(y)):
            return True
        else:
            return False


def lcs(x, y, m, n):
    matrix = [[0 for j in range(n + 1)] for i in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                matrix[i][j] = 0
            elif x[i - 1] == y[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])

    return matrix[m][n]


def check_different_char(x, y, n):
    similarity = 0
    for pointer in range(n):
        if x[pointer] == y[pointer]:
            similarity += 1
    if similarity >= n-1:
        return True
    else:
        return False


# input
first_line = input().split()
k = int(first_line[0])
q = int(first_line[1])
words = input().split()

questions = []

for i in range(q):
    question = input().split()
    questions.append(question)

# create a graph with words as nodes and edges as available transformation
g = Graph()
g.make(words)

matrix = [[[]for j in range(k)]for i in range(k)]
dic = {}
i = 0
for word in words:
    dic[word] = i
    i += 1
for word in words:
    for other_word in words:
        if not matrix[dic[word]][dic[other_word]] == []:
            continue
        path = g.find_shortest_path(word, other_word)
        matrix[dic[word]][dic[other_word]] = path
        matrix[dic[other_word]][dic[word]] = path[::-1]


# find all paths between 2 strings of each question
for question in questions:
    if (question[0] in g.graph.keys()) and (question[1] in g.graph.keys()):
        path = matrix[dic[question[0]]][dic[question[1]]]
        if path == []:
            print('*')
        else:
            for node in path:
                print(node, end=' ')
            print('')
    else:
        print('*')