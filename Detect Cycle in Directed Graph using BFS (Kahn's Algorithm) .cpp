/*
We are gonna use Kahn's Algorithm for Topological Sort in this question. Topological Sorting for a graph is only possible if the graph is a DAG.
If we are unable to generate Topological Sort in this question then we can say the graph is not DAG, hence cycle is present in the graph.
Basically, we are doing reverse logic to do this ques.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	queue<int> q;
	   	vector<int> indegree(V, 0);
	   	for(int i=0; i<V; i++) {
	   	    for(auto it : adj[i]) {
	   	        indegree[it]++;
	   	    }
	   	}
	   	
	   	for(int i=0; i<V; i++) {
	   	    if(indegree[i] == 0) {
	   	        q.push(i);
	   	    }
	   	}
	   	
	   	int cnt = 0;
	   	while(!q.empty()) {
	   	    int node = q.front();
	   	    q.pop();
	   	    cnt++;
	   	    for(auto it : adj[node]) {
	   	        indegree[it]--;
	   	        if(indegree[it] == 0) {
	   	            q.push(it);
	   	        }
	   	    }
	   	}
	   	
	   	if(cnt == V)
	   	    return false;
	   	    
	   	return true;
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

