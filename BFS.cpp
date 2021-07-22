/* 
Breadth First Traversal or BFS is basically traversing the adjacent nodes at first and after that we move to the next node.
BFS traversal of a graph is similar to that of the Level Order Traversal of Trees.

## Complete Algorithm:
1. Create a boolean array say visited[] of size V+1 where V is the number of vertices in the graph.
2. Create a Queue, mark the source vertex visited as visited[s] = true and push it into the queue.
3. Until the Queue is non-empty, repeat the below steps:
  - Pop an element from the queue and print the popped element.
  - Traverse all of the vertices adjacent to the vertex poped from the queue.
  - If any of the adjacent vertex is not already visited, mark it visited and push it to the queue.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
    vector<int>bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> bfs;
        vector<int> vis(V+1, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
      int V, E;
      cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
            // string s1;
            // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
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
0 1 2 3 4 
*/

/*
TC: O(N+E)
N is time taken for visiting N nodes, and E is for traveling through adjacent nodes overall.

SC: O(N+E) + O(N) + O(N)
Space for adj list, vis array and queue.
*/
