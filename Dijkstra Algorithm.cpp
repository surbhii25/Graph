/*
Basic Idea: Given a graph and a source vertex in the graph, find the shortest paths from source to all vertices in the given graph.

Dijkstra's algorithm is a variation of the BFS algorithm. In Dijkstra's Algorithm, a SPT(shortest path tree) is generated with given source as root. 
Each node at this SPT stores the value of the shortest path from the source vertex to the current vertex.
Dijkstra's algorithm is very similar to Prim's algorithm for minimum spanning tree. 
Like Prim's MST, we generate a SPT (shortest path tree) with given source as root.

Below is the complete algorithm using priority_queue(min heap) to implement Dijkstra's Algorithm:
1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq. Every item of pq is a pair (weight, vertex). Weight (or distance) is used as the first item of pair as the first item 
   is by default used to compare two pairs.
   
3) Insert source vertex into pq and make its distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array dist[] to print all shortest paths. 

Note: The Dijkstra's Algorithm doesn't work in the case when the Graph has negative edge weight.
*/



/*

*/

/*
Time Complexity: The time complexity of the Dijkstra's Algorithm when implemented using a min heap is O(E * logV), where E is the number of Edges and V is the number of vertices.
Space Complexity: O(N) + O(N) because we used dist array and adj list.
*/
