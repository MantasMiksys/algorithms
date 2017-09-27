/*

# time complexity O(V + E)

def topological_sort_helper(v, visited, stack):
    visited[v] = True

    # for all vertices adjacent to v
    for i in range(G.V):
        if G.is_adjacent(v, i) and not visited[i]:
            topological_sort_helper(i, visited, stack)
    stack.append(v)

def topological_sort():
    n = G.V
    visited = [False] * n

    stack = []

    for i in range(n):
        if not visited[i]:
            topological_sort_helper(i, visited, stack)

    for v in range(n):
        print(stack.pop())



class Graph:
    V = 0
    adj = [] # adjencency matrix

    def __init__(self, V):
        self.V = V
        self.adj = [[0] * V for _ in range(V)]

    def add_edge(self, v, e):
        self.adj[v][e] = 1

    def is_adjacent(self, v, e):
        return self.adj[v][e]

G = Graph(6)
G.add_edge(5, 2)
G.add_edge(5, 0)
G.add_edge(4, 0)
G.add_edge(4, 1)
G.add_edge(2, 3)
G.add_edge(3, 1)

topological_sort()
        
    
*/