from collections import deque


def topological_sort(graph):
    indegree = {node: 0 for node in graph}

    for node in graph:
        for neighbor in graph[node]:
            indegree[neighbor] += 1

    queue = deque(
        node for node in graph
        if indegree[node] == 0
    )

    result = []

    while queue:
        current = queue.popleft()
        result.append(current)

        for neighbor in graph[current]:
            indegree[neighbor] -= 1

            if indegree[neighbor] == 0:
                queue.append(neighbor)

    if len(result) != len(graph):
        return None

    return result


graph = {
    "Programming": ["Data Structures"],
    "Mathematics": ["Algorithms"],
    "Data Structures": ["Algorithms"],
    "Algorithms": ["AI"],
    "AI": [],
}

order = topological_sort(graph)

if order:
    print("Valid learning order:")

    for subject in order:
        print("->", subject)
else:
    print("Cycle detected! No valid ordering.")