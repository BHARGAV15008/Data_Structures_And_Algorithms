// Converting Adjacency matrix of graph to Adjacency List;

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

void printMatrix(int adjMatrix[][7], int size) {
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            printf("%d  ", adjMatrix[i][j]);
        printf("\n");
    }
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

void insertNode (struct GraphAdjacencyList* head, int data) {
    struct GraphAdjacencyList* cNode = createNode(data);
    struct GraphAdjacencyList* tNode = head;
    while (tNode->next != NULL)
        tNode = tNode->next;
    
    tNode->next = cNode;
}

void AdjacencyListToMatrix (struct Graph* graph, int adjmatrix[][7], int size) {
    struct GraphAdjacencyList* gls = NULL;
    int j = 0;
    for (int i = 0; i < size; i++) {
        gls = graph->arr[i]->next;
        while (gls != NULL) {
            j = gls->data;
            adjmatrix[i][j] = 1;
            gls = gls->next;
        }
    }
}

int main (){
    int graph[7][7] = {0};

    struct Graph* graphs = (struct Graph*) malloc(sizeof(struct Graph));
    graphs->size = 7;
    graphs->arr = (struct GraphAdjacencyList**) malloc(graphs->size * sizeof(struct GraphAdjacencyList));

    for (int i = 0; i < 7; i++)
        graphs->arr[i] = createNode(i);

    insertNode(graphs->arr[0], 1);
    insertNode(graphs->arr[0], 2);
    insertNode(graphs->arr[0], 3);
    insertNode(graphs->arr[1], 0);
    insertNode(graphs->arr[1], 3);
    insertNode(graphs->arr[2], 0);
    insertNode(graphs->arr[2], 3);
    insertNode(graphs->arr[2], 4);
    insertNode(graphs->arr[4], 2);
    insertNode(graphs->arr[4], 3);
    insertNode(graphs->arr[4], 5);
    insertNode(graphs->arr[4], 6);
    insertNode(graphs->arr[3], 0);
    insertNode(graphs->arr[3], 1);
    insertNode(graphs->arr[3], 2);
    insertNode(graphs->arr[3], 4);
    insertNode(graphs->arr[5], 4);
    insertNode(graphs->arr[6], 4);

    printMatrix(graph, 7);
    AdjacencyListToMatrix (graphs, graph, 7);
    printf("\n\n");
    printMatrix(graph, 7);

    
    
    return 0;
}