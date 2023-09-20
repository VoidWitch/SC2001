//create visited arr, min distance arr, prev index arr, priority q
//start from source vertex, mark visited

//for each adj node connected to vertex, update weight into dist arr
//update prev index array for nodes compared
//priority q sorts least weighted node to explore

//explore next node, mark as visited
//repeat for each adj node, update weight and prev index
//if d[v] > d[u] + w[u,v], d[v] = d[u] + w[u,v]
//weighted nodes sorted in priority queue

//when reach sink vertex, backtrack prev index array to determine shortest path

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 // Number of vertices in the graph arbitrary

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;   //INT_MAX is infinity

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;   //priority
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];     // dist
    int sptSet[V];   // visited

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;  //initialize to INF
        sptSet[i] = 0;      //initialize unvisited
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 1, 0, 0},
        {2, 0, 4, 0, 0, 0},
        {0, 4, 0, 3, 5, 0},
        {1, 0, 3, 0, 1, 8},
        {0, 0, 5, 1, 0, 2},
        {0, 0, 0, 8, 2, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
