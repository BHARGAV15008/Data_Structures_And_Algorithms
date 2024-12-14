#include <stdio.h>
#include <stdlib.h>

void simpleDFS (int graph[7][7], int visited[], int size, int node) {
    printf("%d  ", node);
    visited[node] = 1;
    for (int i = 0; i < size; i++)
        if (graph[node][i] == 1 && !visited[i])
            simpleDFS(graph, visited, size, i);
}

int main (){
    // Graph Initialization and DFS implementation;
    int visited[] = {0, 0, 0, 0, 0, 0, 0};

    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    simpleDFS(graph, visited, 7, 0);
    
    return 0;
}