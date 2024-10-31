Navigation Graph Project
This project is a navigation graph application that demonstrates the use of graph-based data structures and algorithms to simulate a basic route-finding system in a navigation context. Using Dijkstra's algorithm, it finds the shortest path between two specified locations (nodes) in a directed, weighted graph that represents a city or road network.


Overview
The Navigation Graph Project is a C-based application that models a navigation system for finding optimal routes between locations. This project allows users to:

Represent locations as nodes and roads as edges with travel time or distance weights.
Use Dijkstra’s algorithm to calculate the shortest route between two locations in the graph.
Explore the impact of adding nodes and edges on the route calculation.
The project also demonstrates the limitations of Dijkstra’s algorithm for more complex routing problems, such as the Traveling Salesman Problem (TSP), and suggests potential solutions and optimizations.

Features
Graph Representation: Uses an adjacency list to represent nodes (locations) and weighted edges (roads with travel times/distances).
Shortest Path Calculation: Implements Dijkstra’s algorithm to find the shortest path between two specified locations.
Flexible Node and Edge Input: Allows custom nodes and edges to represent a variety of navigation scenarios.
Modular Design: Easy-to-read code with modular functions for future expansion, such as adding alternative algorithms.

Installation

Clone the repository:
git clone https://github.com/your-username/navigation-graph-project.git

Navigate into the project directory:
cd navigation-graph-project

Compile the code:
gcc main.c -o navigation_graph

Usage
Run the program:
./navigation_graph

The program will initialize a sample navigation graph with pre-set locations and roads.

Output will show the graph structure (locations and roads) and the shortest path from a start location to all other locations, as calculated by Dijkstra’s algorithm.

To customize, modify the main function in main.c to add new nodes and edges or change travel times.

Example Output
sql
Copy code
Navigation Graph:
Location 0: -> 2 (travel time 10) -> 1 (travel time 15)
Location 1: -> 3 (travel time 12)
...

Shortest travel times from Location 0:
Location    Travel Time from Start
0           0
1           15
...

Limitations
While Dijkstra's algorithm is effective for finding the shortest path between two locations, it cannot solve more complex graph problems such as the Traveling Salesman Problem (TSP). TSP requires finding the shortest route that visits each location exactly once and returns to the start, which is beyond Dijkstra's capability. Instead, TSP requires:

Dynamic Programming (Held-Karp Algorithm)
Approximation Algorithms (e.g., Christofides' algorithm for near-optimal results)
Heuristics (e.g., genetic algorithms or ant colony optimization for large datasets)

Future Work
Implement Alternative Algorithms: Add algorithms such as A* for more efficient pathfinding in larger graphs or introduce TSP-specific solutions.
Real-World Datasets: Integrate real-world navigation datasets for testing route optimization.
Graph Generation Tools: Allow random or user-defined graph generation for testing purposes.
Interactive Route Visualization: Develop a UI component to visualize routes in a simulated navigation map.
