/*
Depth First Traversal or DFS traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. 
There is a cycle in a graph only if there is a back edge present in the graph. 
A back edge is an edge that is from a node to itself (self-loop) or one of its ancestor in the tree produced by DFS.

For a disconnected graph, Get the DFS forest as output. To detect cycle, check for a cycle in individual trees by checking back edges.
To detect a back edge, keep track of vertices currently in the recursion stack of function for DFS traversal. 
If a vertex is reached that is already in the recursion stack, then there is a cycle in the tree. 
The edge that connects the current vertex to the vertex in the recursion stack is a back edge.

## Algorithm: 
1. Create the graph using the given number of edges and vertices.
2. Create a recursive function that initializes the current index or vertex, visited, and recursion stack.
3. Mark the current node as visited and also mark the index in recursion stack.
4. Find all the vertices which are not visited and are adjacent to the current node. 
   Recursively call the function for those vertices, If the recursive function returns true, return true.
5. If the adjacent vertices are already marked in the recursion stack then return true.
6. Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true return true. 
   Else if for all vertices the function returns false return false.
*/



/*

*/

/*
TC: O(V+E)
Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).

SC: O(V)
To store the visited and recursion stack O(V) space is needed.
*/
