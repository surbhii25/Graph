/*
Depth-First Traversal or the DFS traversal of a Graph is used to traverse a graph depth wise.
That is, it in this traversal method, we start traversing the graph from a node and keep on going in the same direction as far as possible. When no nodes are left to be traversed along the current path, backtrack to find a new possible path and repeat this process until all of the nodes are visited.
*/



/*
TC: O(N+E)
N is time taken for visiting N nodes, and E is for traveling through adjacent nodes overall.
SC: O(N+E) + O(N) + O(N)
Space for adj list, vis array and queue.
*/
