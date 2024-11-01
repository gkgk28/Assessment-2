#include <stdio.h>
#include "Graph.h"
int main()
{
    // create an array of graphs
    Graph* graphs[5];

    // create 5 graphs
    for (int i = 0; i < 5; i++)
    {
        graphs[i] = createGraph(5);
    }

    addEdge(graphs[0], 0, 1, 8);
    addEdge(graphs[0], 0, 2, 3);
    addEdge(graphs[0], 1, 2, 5);
    addEdge(graphs[0], 1, 3, 2);
    addEdge(graphs[0], 2, 3, 7);
    addEdge(graphs[0], 2, 4, 4);
    addEdge(graphs[0], 3, 4, 6);

    addEdge(graphs[1], 0, 1, 4);
    addEdge(graphs[1], 0, 2, 6);
    addEdge(graphs[1], 1, 2, 9);
    addEdge(graphs[1], 1, 3, 3);
    addEdge(graphs[1], 2, 3, 5);
    addEdge(graphs[1], 2, 4, 1);
    addEdge(graphs[1], 3, 4, 7);

    addEdge(graphs[2], 0, 1, 7);
    addEdge(graphs[2], 0, 2, 2);
    addEdge(graphs[2], 1, 2, 6);
    addEdge(graphs[2], 1, 3, 8);
    addEdge(graphs[2], 2, 3, 4);
    addEdge(graphs[2], 2, 4, 9);
    addEdge(graphs[2], 3, 4, 5);

    addEdge(graphs[3], 0, 1, 3);
    addEdge(graphs[3], 0, 2, 7);
    addEdge(graphs[3], 1, 2, 1);
    addEdge(graphs[3], 1, 3, 6);
    addEdge(graphs[3], 2, 3, 8);
    addEdge(graphs[3], 2, 4, 5);
    addEdge(graphs[3], 3, 4, 2);

    addEdge(graphs[4], 0, 1, 5);
    addEdge(graphs[4], 0, 2, 9);
    addEdge(graphs[4], 1, 2, 3);
    addEdge(graphs[4], 1, 3, 7);
    addEdge(graphs[4], 2, 3, 4);
    addEdge(graphs[4], 2, 4, 6);
    addEdge(graphs[4], 3, 4, 8);

    printf("Dijkstra's Algorithm on first graph:\n");
    dijkstra(graphs[0], 0);
    printf("A* algorithm on first graph\n");
    A_star(graphs[0], 0, 4);
    // run a* algorithm on the second graph

    printf("Dijkstra's Algorithm on second graph:\n");
    A_star(graphs[1], 0, 4);
    printf("A* algorithm on second graph\n");
    dijkstra(graphs[1], 0);

    printf("Dijkstra's Algorithm on third graph:\n");
    // run dijkstra's algorithm on the third graph
    dijkstra(graphs[2], 0);
    printf("A* algorithm on third graph\n");
    // run a* algorithm on the third graph
    A_star(graphs[2], 0, 4);

    printf("Dijkstra's Algorithm on fourth graph:\n");
    // run a* algorithm on the fourth graph
    A_star(graphs[3], 0, 4);

    printf("A* algorithm on fourth graph\n");
    // run dijkstra's algorithm on the fourth graph
    dijkstra(graphs[3], 0);

    printf("Dijkstra's Algorithm on fifth graph:\n");

    // run dijkstra's algorithm on the fifth graph
    dijkstra(graphs[4], 0);
    printf("A* algorithm on fifth graph\n");
    // run a* algorithm on the fifth graph
    A_star(graphs[4], 0, 4);

    return 0;
}