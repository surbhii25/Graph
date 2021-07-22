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

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
        bool cycleCheck(int node, vector<int> adj[], int vis[], int dfsVis[]) {
            vis[node] = 1;
            dfsVis[node] = 1;

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    if(cycleCheck(it, adj, vis, dfsVis))
                        return true;
                }
                else if(dfsVis[it])
                    return true;
            }

            dfsVis[node] = 0;
            return false;
        }
    
	//Function to detect cycle in a directed graph.
        bool isCyclic(int V, vector<int> adj[]) 
        {
            // code here
            int vis[V], dfsVis[V];
            memset(vis, 0, sizeof vis);
            memset(dfsVis, 0, sizeof dfsVis);

            for(int i=0; i<V; i++) {
                if(!vis[i]) {
                    if(cycleCheck(i, adj, vis, dfsVis)) {
                        return true;
                    }
                }
            }
            return false;

        }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

/*
For Input:
4 4
0 1
1 2
2 3
3 3

Your Output is: 
1
*/

/*
TC: O(V+E)
Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).

SC: O(V)
To store the visited and recursion stack O(V) space is needed.
*/
