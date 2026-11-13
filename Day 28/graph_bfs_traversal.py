from collections import deque


def bfs(graph, start):
    visited = set()
    queue = deque([start])

    while queue:
        node = queue.popleft()

        if node not in visited:
            print(node, end=" ")
            visited.add(node)

            for neighbor in graph.get(node, []):
                if neighbor not in visited:
                    queue.append(neighbor)


graph = {}

n = int(input("Enter number of nodes: "))

for i in range(n):
    node = input(f"Enter node {i + 1}: ")
    neighbors = input(
        f"Enter neighbors of {node}, separated by spaces: "
    ).split()

    graph[node] = neighbors

start = input("Enter starting node: ")

if start in graph:
    print("BFS Traversal:")
    bfs(graph, start)
    print()
else:
    print("Starting node does not exist.")
    