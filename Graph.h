#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "node.h" // Make sure to include node.h for the Node structure

typedef struct Graph
{
    Node** adjList; // Array of adjacency lists
    int numNodes;   // Number of nodes in the graph
} Graph;

// Function prototypes
Graph* createGraph(int numNodes);
void addEdge(Graph* graph, int src, int dest, int weight);
void A_star(Graph* graph, int startNode, int endNode);
void dijkstra(Graph* graph, int startNode);

#endif

