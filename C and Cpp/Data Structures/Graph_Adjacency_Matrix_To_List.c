// Converting Adjacency List of graph to Adjacency Matrix;

#include <stdio.h>
#include <stdlib.h>

struct GraphAdjacencyList {
    int data;
    struct GraphAdjacencyList* next;
};

struct Graph {
    int size;
    struct GraphAdjacencyList** arr;
};

struct GraphAdjacencyList* createNode(int data) {
    struct GraphAdjacencyList* cNode = (struct GraphAdjacencyList*) malloc(sizeof(struct GraphAdjacencyList));
    cNode->data = data;
    cNode->next = NULL;
    return cNode;
}

void traversalList(struct GraphAdjacencyList* head){
    struct GraphAdjacencyList* cNode;
    cNode = head;
    printf("\nYour List is ... \n");
    while (cNode != NULL) {
        printf("%d --> ", cNode->data);
        cNode = cNode->next;
    }
    printf("NULL\n");
}

void AdjacencyMatrixToList (struct Graph* graph, int adjMatrix[][7], int size) {
    struct GraphAdjacencyList* cNode = NULL;
    struct GraphAdjacencyList* tNode = NULL;
    if (graph == NULL) {
        graph = (struct Graph*) malloc(sizeof(struct Graph));
        graph->size = size;
        graph->arr = (struct GraphAdjacencyList**) malloc(graph->size * sizeof(struct GraphAdjacencyList));
    }

    for (int i = 0; i < size; i++) {
        graph->arr[i] = createNode(i);
        tNode = graph->arr[i];
        for (int j = 0; j < size; j++){
            if (adjMatrix[i][j] == 1) {
                cNode = createNode(j);
                tNode->next = cNode;
                tNode = tNode->next;
            }
        }
    }

    for (int i = 0; i < size; i++) 
        traversalList(graph->arr[i]);
}

int main (){
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    struct Graph* graphs = NULL;
    AdjacencyMatrixToList(graphs, graph, 7);
    
    
    return 0;
}