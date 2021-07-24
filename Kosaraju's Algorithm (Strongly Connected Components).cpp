/*
A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly 
connected subgraph.
We can find all strongly connected components in O(V+E) time using Kosaraju's algorithm. 

# Kosaraju's algorithm:
1. Create an empty stack 'S' and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. 
2. Reverse directions of all arcs to obtain the transpose graph.
3. One by one pop a vertex from S while S is not empty. Let the popped vertex be 'v'. Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly 
   connected component of v.
   
How does this work: The above algorithm is DFS based. It does DFS two times. DFS of a graph produces a single tree if all vertices are reachable from the DFS starting point. 
Otherwise, DFS produces a forest. So DFS of a graph with only one SCC always produces a tree. 
The important point to note is DFS may produce a tree or a forest when there are more than one SCCs depending upon the chosen starting point.

Applications: SCC algorithms can be used as a first step in many graph algorithms that work only on strongly connected graph.
In social networks, a group of people are generally strongly connected (For example, students of a class or any other common place). 
Many people in these groups generally like some common pages or play common games. The SCC algorithms can be used to find such groups and suggest the commonly liked pages 
or games to the people in the group who have not yet liked commonly liked a page or played a game.
*/



/*
For Input:
5 5
1 0
0 2
2 1
0 3
3 4

Your Output is: 
3
*/

/*
Time Complexity: The above algorithm calls DFS, finds reverse of the graph and again calls DFS. DFS takes O(V+E) for a graph represented using adjacency list. 
Reversing a graph also takes O(V+E) time. For reversing the graph, we simple traverse all adjacency lists.
*/
