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

// Dijkstra's Algorithm for shortest path
void dijkstra(Graph *graph, int start)
{
    int distances[MAX_NODES];
    int visited[MAX_NODES] = {0};

    // Initialize distances to maximum
    for (int i = 0; i < graph->numNodes; i++)
    {
        distances[i] = INT_MAX;
    }
    distances[start] = 0;

    // Dijkstra's main loop
    for (int i = 0; i < graph->numNodes - 1; i++)
    {
        int minDist = INT_MAX, minIndex;

        // Find the minimum distance node
        for (int j = 0; j < graph->numNodes; j++)
        {
            if (!visited[j] && distances[j] <= minDist)
            {
                minDist = distances[j];
                minIndex = j;
            }
        }

        // Mark the chosen node as visited
        visited[minIndex] = 1;

        // Update distances of adjacent nodes
        Node *currentNode = graph->adjList[minIndex];
        while (currentNode != NULL)
        {
            int dest = currentNode->destination;
            int weight = currentNode->weight;

            if (!visited[dest] && distances[minIndex] != INT_MAX &&
                distances[minIndex] + weight < distances[dest])
            {
                distances[dest] = distances[minIndex] + weight;
            }
            currentNode = currentNode->next;
        }
    }

    // Print shortest distances
    printf("Node\tDistance from Start\n");
    for (int i = 0; i < graph->numNodes; i++)
    {
        printf("%d\t\t%d\n", i, distances[i]);
    }
}

int main()
{
    int numNodes = 5;
    Graph *graph = createGraph(numNodes);

    // Adding edges with weights
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 20);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 2, 1);

    // Run Dijkstra's algorithm from node 0
    printf("Running Dijkstra's Algorithm from node 0:\n");
    dijkstra(graph, 0);

    return 0;
}
