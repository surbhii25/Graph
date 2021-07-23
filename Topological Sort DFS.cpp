/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a DAG.

We can modify DFS to find Topological Sorting of a graph. In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices. 
In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices,
then push it to a stack. Finally, print contents of the stack. Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on)
are already in stack.

# Applications: Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. 
In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, 
logic synthesis, determining the order of compilation tasks to perform in makefiles, data serialization, and resolving symbol dependencies in linkers
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
        void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
            vis[node] = 1;

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    findTopoSort(it, vis, st, adj);
                }
            }
            st.push(node);

        }
	
	//Function to return list containing vertices in Topological order. 
        vector<int> topoSort(int V, vector<int> adj[]) 
        {
            // code here
            stack<int> st;
            vector<int> vis(V,0);
            for(int i=0; i<V; i++) {
                if(!vis[i]) {
                    findTopoSort(i, vis, st, adj);
                }
            }

            vector<int> topo;
            while(!st.empty()) {
                topo.push_back(st.top());
                st.pop();
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

// Note: Here, we can also use vector instead of stack. If the vector is used then print the elements in reverse order to get the topological sorting.

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
The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is.

AS: O(V)
The extra space is needed for the stack.
*/
