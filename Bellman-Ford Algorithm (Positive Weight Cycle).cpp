/*
Problem: Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph.

Dijkstra doesn't work for Graphs with negative weight edges, Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems.
But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.

Basic Idea: Relax all the edges N-1 times.
            if dist[u] + wt < dist[v]
                dist[v] = dist[u] + wt;

# Algorithm: Following are the detailed steps.
  - Input: Graph and a source vertex src.
  - Output: Shortest distance to all vertices from src. If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.

1. This step initializes distances from source to all vertices as infinite and distance to source itself as 0. 
   Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.
2. This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
   Do following for each edge u-v:
   If dist[v] > dist[u] + weight of edge uv, then update dist[v] as: dist[v] = dist[u] + weight of edge uv.
3. This step reports if there is a negative weight cycle in graph. Do following for each edge u-v. If dist[v] > dist[u] + weight of edge uv, 
   then "Graph contains negative weight cycle".

The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn't contain a negative weight cycle. 
If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle.

# How does this work: Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottom-up manner. 
It first calculates the shortest distances which have at most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. 
After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. 
There can be maximum |V| - 1 edge in any simple path, that is why the outer loop runs |v| - 1 time. 
The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at most i edges, 
then an iteration over all edges guarantees to give shortest path with at-most (i+1) edge.
*/

#include<bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution{
    public:
    /*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
        vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
            // Code here
            vector<int> dist(V, 1e8);

            set<pair < pair<int,int> , int > > edges;

            for(int i=0; i<adj.size(); i++) {
                int u = adj[i][0];
                int v = adj[i][1];
                int w = adj[i][2];
                edges.insert({{u,v} , w});
            }

            dist[S] = 0;

            for(int i=1; i<V; i++) {
                for(auto it : edges) {
                    int u = it.first.first;
                    int v = it.first.second;
                    int w = it.second;
                    if(dist[u] + w < dist[v] && dist[u] < 1e8) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            return dist;
        }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


/*
For Input:
2 1
0 1 9
0

Your Output is: 
0 9 
*/

/*
TC: O(V-1) x O(E) = O(V * E)
SC: O(N)
*/
