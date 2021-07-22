/* 
Breadth First Traversal or BFS is basically traversing the adjacent nodes at first and after that we move to the next node.
BFS traversal of a graph is similar to that of the Level Order Traversal of Trees.

## Complete Algorithm:
1. Create a boolean array say visited[] of size V+1 where V is the number of vertices in the graph.
2. Create a Queue, mark the source vertex visited as visited[s] = true and push it into the queue.
3. Until the Queue is non-empty, repeat the below steps:
  - Pop an element from the queue and print the popped element.
  - Traverse all of the vertices adjacent to the vertex poped from the queue.
  - If any of the adjacent vertex is not already visited, mark it visited and push it to the queue.
*/



/*
TC: O(N+E)
N is time taken for visiting N nodes, and E is for traveling through adjacent nodes overall.

SC: O(N+E) + O(N) + O(N)
Space for adj list, vis array and queue.
*/
