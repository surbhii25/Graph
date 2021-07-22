/*
Depth-First Traversal or the DFS traversal of a Graph is used to traverse a graph depth wise.
That is, it in this traversal method, we start traversing the graph from a node and keep on going in the same direction as far as possible.
When no nodes are left to be traversed along the current path, backtrack to find a new possible path and repeat this process until all of the nodes are visited.
We can implement the DFS traversal algorithm using a recursive approach. While performing the DFS traversal the graph may contain a cycle and the same node can be visited again, 
so in order to avoid this we can keep track of visited array using an auxiliary array.
On each step of the recursion mark, the current vertex visited and call the recursive function again for all the adjacent vertices.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
        void dfs(int i, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
            storeDfs.push_back(i);
            vis[i] = 1;
            for(auto it : adj[i]) {
                if(!vis[it]) {
                    dfs(it, vis, adj, storeDfs);
                }
            }
        }
        
    	//Function to return a list containing the DFS traversal of the graph.
    	vector<int>dfsOfGraph(int V, vector<int> adj[])
    	{
    	    // Code here
    	    vector<int> storeDfs;
    	    vector<int> vis(V+1, 0);
    	    
    	    for(int i=0; i<V; i++) {
    	        if(!vis[i]) {
    	            dfs(i, vis, adj, storeDfs);
    	        }
    	    }
    	    
    	    return storeDfs;
    	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}

/*
For Input:
5 4
0 1 
0 2
0 3 
2 4

Your Output is: 
0 1 2 4 3 
*/

/*
TC: O(N+E)
N is time taken for visiting N nodes, and E is for traveling through adjacent nodes overall.
SC: O(N+E) + O(N) + O(N)
Space for adj list, vis array and queue.
*/
