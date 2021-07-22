#include <iostream>
using namespace std;

bool A[10][10];

void initialize() {
  for(int i = 0; i < 10; ++i)
    for(int j = 0; j < 10; ++j)
      A[i][j] = false;
}

int main() {
  int x, y, nodes, edges;
  initialize();                                 //Since there is no edge initially
  cin >> nodes;                                 //Number of nodes
  cin >> edges;                                 //Number of edges
  for(int i = 0; i < edges; ++i) {
    cin >> x >> y;
    A[x][y] = true;                             //Mark the edges from vertex x to vertex y
}

// Pros: Representation is easier to implement and follow. Removing an edge takes O(1) time. Queries like whether there is an edge from vertex 'u' to vertex 'v' are efficient and can be done O(1).

// Cons: Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges), it consumes the same space. Adding a vertex is O(V^2) time.
