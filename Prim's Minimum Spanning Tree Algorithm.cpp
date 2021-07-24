/*
# What is Minimum Spanning Tree?
Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. 
A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, 
connected and undirected graph is a spanning tree with weight less than or equal to the weight of every other spanning tree. 
The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

Number of edges in a minimum spanning tree: A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.

# Prim's Algorithm
Prim’s algorithm is also a Greedy algorithm. It starts with an empty spanning tree. The idea is to maintain two sets of vertices. 
The first set contains the vertices already included in the MST, the other set contains the vertices not yet included. 
At every step, it considers all the edges that connect the two sets, and picks the minimum weight edge from these edges. 
After picking the edge, it moves the other endpoint of the edge to the set containing MST.

A group of edges that connects two set of vertices in a graph is called cut in graph theory. So, at every step of Prim’s algorithm, we find a cut 
(of two sets, one contains the vertices already included in MST and other contains rest of the vertices), pick the minimum weight edge from the cut 
and include this vertex to MST Set (the set that contains already included vertices).

How does Prim's Algorithm Work: The idea behind Prim's algorithm is simple, a spanning tree means all vertices must be connected. 
So the two disjoint subsets (discussed above) of vertices must be connected to make a Spanning Tree. 
And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

# Algorithm:
1. Create a set mstSet that keeps track of vertices already included in MST.
2. Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first.
3. While mstSet doesn't include all vertices:
  - Pick a vertex u which is not there in mstSet and has minimum key value.
  - Include u to mstSet.
  - Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices. 
    For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v.

The idea of using key values is to pick the minimum weight edge from cut. The key values are used only for vertices which are not yet included in MST, 
the key value for these vertices indicate the minimum weight edges connecting them to the set of vertices included in MST.
*/



/*
For Input:
3 3
0 1 5
1 2 3
0 2 1

Your Output is: 
6
*/

/*

*/
