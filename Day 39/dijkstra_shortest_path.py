import heapq


def dijkstra(graph, start, end):
    distances = {node: float("inf") for node in graph}
    previous = {}

    distances[start] = 0
    queue = [(0, start)]

    while queue:
        current_distance, current = heapq.heappop(queue)

        if current_distance > distances[current]:
            continue

        if current == end:
            break

        for neighbor, weight in graph[current]:
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                previous[neighbor] = current

                heapq.heappush(
                    queue, (distance, neighbor)
                )

    if distances[end] == float("inf"):
        return None, float("inf")

    path = []
    current = end

    while current != start:
        path.append(current)
        current = previous[current]

    path.append(start)
    path.reverse()

    return path, distances[end]


graph = {
    "A": [("B", 4), ("C", 2)],
    "B": [("A", 4), ("C", 1), ("D", 5)],
    "C": [("A", 2), ("B", 1), ("D", 8)],
    "D": [("B", 5), ("C", 8)]
}

start = input("Starting node: ").upper()
end = input("Destination node: ").upper()

if start not in graph or end not in graph:
    print("Invalid node.")
else:
    path, distance = dijkstra(graph, start, end)

    if path is None:
        print("No path found.")
    else:
        print("Shortest path:", " -> ".join(path))
        print("Total distance:", distance)