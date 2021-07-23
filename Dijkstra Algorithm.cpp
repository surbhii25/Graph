/*
Problem: Given a graph and a source vertex in the graph, find the shortest paths from source to all vertices in the given graph.

Dijkstra's algorithm is a variation of the BFS algorithm. In Dijkstra's Algorithm, a SPT(shortest path tree) is generated with given source as root. 
Each node at this SPT stores the value of the shortest path from the source vertex to the current vertex.
Dijkstra's algorithm is very similar to Prim's algorithm for minimum spanning tree. 
Like Prim's MST, we generate a SPT (shortest path tree) with given source as root.

Below is the complete algorithm using priority_queue(min heap) to implement Dijkstra's Algorithm:
1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq. Every item of pq is a pair (weight, vertex). Weight (or distance) is used as the first item of pair as the first item 
   is by default used to compare two pairs.
   
3) Insert source vertex into pq and make its distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array dist[] to print all shortest paths. 

Note: The Dijkstra's Algorithm doesn't work in the case when the Graph has negative edge weight.
*/

#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
typedef pair<int,int> iPair;

class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // priority_queue <Type, vector<Type>, ComparisonType > min_heap;
        priority_queue <iPair, vector<iPair>, greater<iPair> > pq;
        // pq(min-heap) : In pair => (dist,from)
        
        vector<int> dist(V, INF);
        
        dist[S] = 0;
        pq.push(make_pair(0, S));
        
        while(!pq.empty()) {
            
            int u = pq.top().second;
            pq.pop();
            
            for(auto it : adj[u]) {
                
                int v = it[0];
                int weight = it[1];
                
                if(dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
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
Time Complexity: O(V * logV)
The time complexity of the Dijkstra's Algorithm when implemented using a min heap is O(E * logV), where E is the number of Edges and V is the number of vertices.

Space Complexity: O(N) + O(N) because we used dist array and adj list.
*/
