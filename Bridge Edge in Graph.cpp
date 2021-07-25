/*
Given an undirected graph of V vertices and E edges and another edge (c-d), the task is to find if the given edge is a bridge in graph, i.e., removing the edge disconnects 
the graph.

An edge in an undirected connected graph is a bridge iff removing it disconnects the graph. 
For a disconnected undirected graph, definition is similar, a bridge is an edge removing which increases number of disconnected components.

Like Articulation Points, bridges represent vulnerabilities in a connected network and are useful for designing reliable networks. 
For example, in a wired computer network, an articulation point indicates the critical computers and a bridge indicates the critical wires or connections.

How to find all bridges in a given graph?
A simple approach is to one by one remove all edges and see if removal of an edge causes disconnected graph. Following are steps of a simple approach for a connected graph.
1. For every edge (u, v), do following
  - Remove (u, v) from graph.
  - See if the graph remains connected (We can either use BFS or DFS)
  - Add (u, v) back to the graph.
The time complexity of the above method is O(E*(V+E)) for a graph represented using adjacency list.

Another Method:
A O(V+E) algorithm to find all Bridges is similar to that of O(V+E) algorithm for Articulation Points. We do DFS traversal of the given graph. 
In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge if there does not exist any other alternative to reach u or an ancestor of u from subtree rooted with v.
## The condition for an edge (u, v) to be a bridge is, "low[v] > disc[u]".
*/



/*
For Input:
4 3
0 1
1 2
2 3
1 2

Your Output is: 
1
*/

/*
TC: Time complexity is same as DFS which is O(V+E) for adjacency list representation of graph.
SC: O(V)
*/
