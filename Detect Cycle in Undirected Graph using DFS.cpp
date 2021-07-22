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

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
        bool checkCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
            vis[node] = 1;
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    if(checkCycle(it, node, vis, adj))
                        return true;
                }
                else if(it != parent)
                    return true;
            }
            return false;
        }
    
        //Function to detect cycle in an undirected graph.
        bool isCycle(int V, vector<int>adj[])
        {
            // Code here
            vector<int> vis(V+1, 0);
            for(int i=0; i<V; i++) {
                if(!vis[i]) {
                    if(checkCycle(i, -1, vis, adj))
                        return true;
                }
            }
            return false;
        }
};

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else 
            cout << "0\n";
	}
	return 0;
}

/*
For Input:
5 5
0 4
1 2
1 4
2 3
3 4

Your Output is: 
1
*/

/*
TC: O(V+E)
The program does a simple DFS Traversal of the graph which is represented using adjacency list. So the time complexity is O(V+E)

SC: O(V)
To store the visited array O(V) space is required.
*/
