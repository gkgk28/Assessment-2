#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Node.h"
#include "Graph.h"
#include "node.h"

void A_star(Graph* graph, int start, int end)
{
    int distances[MAX_NODES];
    int visited[MAX_NODES] = { 0 };

    // Initialize distances to maximum
    for (int i = 0; i < graph->numNodes; i++)
    {
        distances[i] = INT_MAX;
    }
    distances[start] = 0;

    // A* main loop
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
        Node* currentNode = graph->adjList[minIndex];
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