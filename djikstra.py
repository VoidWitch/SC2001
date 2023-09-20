import heapq

def dijkstra(graph, start):
    # Initialize distances dictionary with infinite values for all nodes except the start node.
    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    # Priority queue to keep track of nodes to visit based on their distances.
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        # Skip if we've already processed this node with a shorter distance.
        if current_distance > distances[current_node]:
            continue

        # Visit each neighbor of the current node and update their distances.
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            # If this path is shorter than the currently known distance, update it.
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Example usage:
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}
start_node = 'A'

shortest_distances = dijkstra(graph, start_node)
print(shortest_distances)
