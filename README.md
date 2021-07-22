# Graph Algorithms

A Graph is a data structure that consists of the following two components:
1. A finite set of vertices also called nodes.
2. A finite set of ordered pair of the form (u, v) called as edge. The pair is ordered because (u, v) is not the same as (v, u) in case of a directed graph(digraph). The pair of the form (u, v) indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.

### Graphs are used to represent many real-life applications:
1. Graphs are used to represent networks. The networks may include paths in a city or telephone network or circuit network. For example: Google GPS.
2. Graphs are also used in social networks like linkedIn, Facebook. For example, in Facebook, each person is represented with a vertex(or node). Each node is a structure and contains information like person id, name, gender and locale.

## Directed and Undirected Graphs
1. **Directed Graphs:** The Directed graphs are such graphs in which edges are directed in a single direction.
![image](https://user-images.githubusercontent.com/81489001/126601670-313b87b7-3a96-456b-a399-b41037714524.png)

2. **Undirected Graphs:** Undirected graphs are such graphs in which the edges are directionless or in other words bi-directional. That is, if there is an edge between vertices u and v then it means we can use the edge to go from both u to v and v to u.
![image](https://user-images.githubusercontent.com/81489001/126601735-102bc5a4-39f7-4b76-b11b-5d31b1a1d4fe.png)

## Representing Graphs
1. **Adjacency Matrix:** The Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j. Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent weighted graphs. If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w.
![image](https://user-images.githubusercontent.com/81489001/126602077-807b446e-ad4c-40c7-a299-6fc41965bbb6.png)

2. **Adjacency List:** Graph can also be implemented using an array of lists. That is every index of the array will contain a complete list. Size of the array is equal to the number of vertices and every index i in the array will store the list of vertices connected to the vertex numbered i. Let the array be array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs.
![image](https://user-images.githubusercontent.com/81489001/126602327-ed7a6cd2-0176-4fdc-86de-d675bc2448a9.png)

