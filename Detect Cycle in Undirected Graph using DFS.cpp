/*
Run a DFS from every unvisited node. Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. 
There is a cycle in a graph only if there is a back edge present in the graph. 
A back edge is an edge that is joining a node to itself (self-loop) or one of its ancestor in the tree produced by DFS. 
To find the back edge to any of its ancestor keep a visited array and if there is a back edge to any visited node then there is a loop and return true.

## Algorithm: 
1. Create the graph using the given number of edges and vertices.
2. Create a recursive function that have current index or vertex, visited array and parent node.
3. Mark the current node as visited .
4. Find all the vertices which are not visited and are adjacent to the current node. 
   Recursively call the function for those vertices, If the recursive function returns true return true.
5. If the adjacent node is not parent and already visited then return true.
6. Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true, return true.
7. Else if for all vertices the function returns false return false.
*/



/*

*/

/*
TC: O(V+E)
The program does a simple DFS Traversal of the graph which is represented using adjacency list. So the time complexity is O(V+E)

SC: O(V)
To store the visited array O(V) space is required.
*/
