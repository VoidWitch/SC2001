import sys

def dijkstra_matrix(graph, start):
    V = len(graph)
    distance = [sys.maxsize] * V
    distance[start] = 0
    visited = [False] * V

    for _ in range(V):
        u = min_distance(distance, visited)
        visited[u] = True
        for v in range(V):
            if not visited[v] and graph[u][v] != 0 and distance[u] + graph[u][v] < distance[v]:
                distance[v] = distance[u] + graph[u][v]

    return distance

def min_distance(distance, visited):
    min_dist = sys.maxsize
    min_index = -1
    for v in range(len(distance)):
        if not visited[v] and distance[v] < min_dist:
            min_dist = distance[v]
            min_index = v
    return min_index

# Example usage
graph_matrix = [
    [0, 4, 0, 0, 0, 0, 0, 8, 0],
    [4, 0, 8, 0, 0, 0, 0, 11, 0],
    [0, 8, 0, 7, 0, 4, 0, 0, 2],
    [0, 0, 7, 0, 9, 14, 0, 0, 0],
    [0, 0, 0, 9, 0, 10, 0, 0, 0],
    [0, 0, 4, 14, 10, 0, 2, 0, 0],
    [0, 0, 0, 0, 0, 2, 0, 1, 6],
    [8, 11, 0, 0, 0, 0, 1, 0, 7],
    [0, 0, 2, 0, 0, 0, 6, 7, 0]
]
start_vertex = 0

result_matrix = dijkstra_matrix(graph_matrix, start_vertex)
print("Shortest distances from vertex", start_vertex, "to all vertices:", result_matrix)


import heapq
import sys

def dijkstra_list(graph, start):
    V = len(graph)
    distance = [sys.maxsize] * V
    distance[start] = 0
    visited = [False] * V
    min_heap = [(0, start)]

    while min_heap:
        dist, u = heapq.heappop(min_heap)
        if not visited[u]:
            visited[u] = True
            for v, weight in graph[u]:
                if not visited[v] and distance[u] + weight < distance[v]:
                    distance[v] = distance[u] + weight
                    heapq.heappush(min_heap, (distance[v], v))

    return distance

# Example usage
graph_list = [
    [(1, 4), (7, 8)],
    [(0, 4), (2, 8), (7, 11)],
    [(1, 8), (3, 7), (5, 4), (8, 2)],
    [(2, 7), (4, 9), (5, 14)],
    [(3, 9), (5, 10)],
    [(2, 4), (3, 14), (6, 2)],
    [(5, 2), (7, 1), (8, 6)],
    [(0, 8), (1, 11), (6, 1), (8, 7)],
    [(2, 2), (6, 6), (7, 7)]
]
start_vertex = 0

result_list = dijkstra_list(graph_list, start_vertex)
print("Shortest distances from vertex", start_vertex, "to all vertices:", result_list)
