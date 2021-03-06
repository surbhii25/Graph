/*
Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges. 

Important Notes:
1. Negative weights are found in various applications of graphs. For example, instead of paying the cost for a path, we may get some advantage if we follow the path.
2. Bellman-Ford works better (better than Dijkstra's) for distributed systems. 
   Unlike Dijksra's where we need to find the minimum value of all vertices, in Bellman-Ford, edges are considered one by one.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n, INT_MAX);
	    
	    dist[0] = 0;
	    
	    for(int i=0; i<n-1; i++) {
	        for(int j=0; j<edges.size(); j++) {
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int w = edges[j][2];
	            
	            if(dist[u] + w < dist[v] && dist[u] < INT_MAX) {
	                dist[v] = dist[u] + w;
	            }
	        }
	    }
	    
	    for(int i=0; i<edges.size(); i++) {
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int w = edges[i][2];
	        
	        if(dist[u] + w < dist[v] && dist[u] < INT_MAX) {
	            return true;
	        }
	    }
	    return false;
	    
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}


/*
For Input:
3 3
0 1 -1
1 2 -2
2 0 -3

Your Output is: 
1
*/

/*
TC: O(n*m)
SC: O(n)
*/
