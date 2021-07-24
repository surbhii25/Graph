/*
Bipartite Graph is a graph that can be colored using 2 colors such that no two adjacent nodes have same colors.
If the graph doesn't contain an odd length cycle then it is a bipartite graph.

# Algorithm:
1. Assign RED color to the source vertex (putting into set U). 
2. Color all the neighbors with BLUE color (putting into set V). 
3. Color all neighbor’s neighbor with RED color (putting into set U). 
4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2. 
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bipartiteBFS(int src, vector<int> adj[], int color[]) {
        queue<int> q;
        q.push(src);
        color[src] = 1;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]) {
                if(color[it] == -1) {
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) {
                    return false;
                }
            }
            
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    memset(color, -1, sizeof color);
	    for(int i=0; i<V; i++) {
	        if(color[i] == -1) {
	            if(!bipartiteBFS(i, adj, color)) {
	                return false;
	            }
	        }
	    }
	 return true;   
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}


/*
For Input:
3 2
0 1
1 2

Your Output is: 
1
*/

/*
TC: O(V+E)
SC: O(V+E) + O(V) + O(V)
*/

