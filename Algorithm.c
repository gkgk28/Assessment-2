#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100 // Define maximum nodes

// Node structure
typedef struct Node
{
    int destination;
    int weight;
    struct Node *next;
} Node;

// Graph structure
typedef struct Graph
{
    Node *adjList[MAX_NODES];
    int numNodes;
} Graph;

// Initialize graph
Graph *createGraph(int numNodes)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++)
    {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Add edge to graph
void addEdge(Graph *graph, int src, int dest, int weight)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->destination = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}


