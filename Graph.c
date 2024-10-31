#include <stdlib.h>
#include "graph.h"

// Create a graph with a given number of nodes
Graph* createGraph(int numNodes)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->adjList = (Node**)malloc(numNodes * sizeof(Node*));

    for (int i = 0; i < numNodes; i++)
    {
        graph->adjList[i] = NULL; // Initialize each adjacency list to NULL
    }
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight)
{
    // Create a new node for the destination
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->destination = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src]; // Insert at the head of the list
    graph->adjList[src] = newNode;
}
