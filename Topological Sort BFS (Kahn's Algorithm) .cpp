/*
A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
# Proof: There’s a simple proof to the above fact is that a DAG does not contain a cycle which means that all paths will be of finite length. 
Now let S be the longest path from u(source) to v(destination). Since S is the longest path there can be no incoming edge to u and no outgoing edge from v, 
if this situation had occurred then S would not have been the longest path.
=> indegree(u) = 0 and outdegree(v) = 0

# Algorithm: Steps involved in finding the topological ordering of a DAG:
 - Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.
 - Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
 - Step-3: Remove a vertex from the queue (Dequeue operation) and then.
           Increment count of visited nodes by 1.
           Decrease in-degree by 1 for all its neighboring nodes.
           If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
 - Step 4: Repeat Step 3 until the queue is empty.
 - Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    queue<int> q;
	    
	    // Compute in-degree (number of incoming edges) for each of the vertex present in the DAG 
	    // and initialize the count of visited nodes as 0
	    vector<int> indegree(V,0);
	    for(int i=0; i<V; i++) {
	        for(auto it : adj[i]) {
	            indegree[it]++;
	        }
	    }
	    
	    // Pick all the vertices with in-degree as 0 and add them into a queue
	    for(int i=0; i<V; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    
	    return topo;
	}
};

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}

/*
For Input:
3 4
3 0
1 0
2 0

Your Output is: 
1
*/

/*
TC: O(V+E)
The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.

AS: O(V)
The queue needs to store all the vertices of the graph. So the space required is O(V).
*/
