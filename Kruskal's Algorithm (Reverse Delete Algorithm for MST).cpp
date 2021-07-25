/*
Reverse Delete algorithm is closely related to Kruskal's algorithm.

In Kruskal's algorithm what we do is : Sort edges by increasing order of their weights. After sorting, we one by one pick edges in increasing order. 
We include current picked edge if by including this in spanning tree not form any cycle until there are V-1 edges in spanning tree, where V = number of vertices.

In Reverse Delete algorithm, we sort all edges in decreasing order of their weights. After sorting, we one by one pick edges in decreasing order. 
We include current picked edge if excluding current edge causes disconnection in current graph. The main idea is delete edge if its deletion does not lead to disconnection 
of graph.

# Algorithm:
1) Sort all edges of graph in non-increasing order of edge weights.

2) Initialize MST as original graph and remove extra edges using step 3.

3) Pick highest weight edge from remaining edges and check if deleting the edge disconnects the graph or not.
    - If disconnects, then we don't delete the edge.
    - Else we delete the edge and continue. 

*/


#include <bits/stdc++.h>
using namespace std;

struct node {
    int u;
    int v;
    int w;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        w = weight;
    }
};

bool comp (node a, node b) {
    return a.w < b.w;
}

class Solution {
  public:
  
    int findPar(int u, vector<int> &parent) {
        if(u == parent[u])
            return u;
        
        return findPar(parent[u], parent);
    }
    
    void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findPar(u, parent);
        v = findPar(v, parent);
        
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
  
    int RevDelMST(int Arr[], int V, int E) {
        // code here
        vector<node> edges;
        
        for(int i=0; i<3*E; i+=3) {
            int u = Arr[i];
            int v = Arr[i+1];
            int w = Arr[i+2];
            
            edges.push_back({u, v, w});
        }
        
        sort(edges.begin(), edges.end(), comp);
        
        vector<int> parent(V);
        for(int i=0; i<V; i++)
            parent[i] = i;
        vector<int> rank(V,0);
        
        int cost = 0;
        vector<pair<int,int>> mst;
        for(auto it : edges) {
            if(findPar(it.v, parent) != findPar(it.u, parent)) {
                cost += it.w;
                mst.push_back({it.u, it.v});
                unionn(it.u, it.v, parent, rank);
            }
        }
        
        return cost;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,E;
        cin>>V>>E;

        int Arr[3*E];
        for(int i=0; i<3*E; i++)
            cin>>Arr[i];

        Solution ob;
        cout << ob.RevDelMST(Arr,V,E) << endl;
    }
    return 0;
}


/*
For Input:
4 5
0 1 10 0 2 6 0 3 5 1 3 15 2 3 4 

Your Output is: 
19
*/

/*
TC: O(E * log E) + O(E * O(4a)) = O(E * log E)
Here, a = alpha; O(4a) is complexity of disjoint set used.
SC: O(E) + O(V) + O(V) = O(V)
*/
