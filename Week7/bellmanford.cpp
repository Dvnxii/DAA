/*Design an algorithm and implement it using a program to solve previous question's
problem using Bellman- Ford's shortest path algorithm.*/

#include <bits\stdc++.h>
using namespace std;
struct Edge {
 int src, dest, weight;
};
void printPath(vector<int>& parent, int vertex, int source) {
 if (vertex == source) {
 cout << source + 1 << " : ";
 return;
 }
 printPath(parent, parent[vertex], source);
 cout << vertex + 1 << " ";
}
void bellmanFord(vector<Edge>& edges, int V, int E, int
source) {
 vector<int> dist(V, INT_MAX);
 vector<int> parent(V, -1);
 dist[source] = 0;
 for (int i = 1; i <= V - 1; ++i) {
 for (int j = 0; j < E; ++j) {
 int u = edges[j].src;
 int v = edges[j].dest;
 int weight = edges[j].weight;
 if (dist[u] != INT_MAX && dist[u] + weight <
dist[v]) {
 dist[v] = dist[u] + weight;
 parent[v] = u;
 }
 }
 }
 // Check for negative-weight cycles
 for (int i = 0; i < E; ++i) {
 int u = edges[i].src;
 int v = edges[i].dest;
 int weight = edges[i].weight;
 if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
{
 cout << "Graph contains negative weight cycle" <<
endl;
 return;
 }
 }
 // Print the shortest paths
 for (int i = 0; i < V; ++i) {
 if (i == source) {
 cout << source + 1 << " : 0" << endl;
 continue;
 }
 if (dist[i] == INT_MAX) {
 cout << "No path from " << source + 1 << " to " << i + 1 <<
endl;
 continue;
 }
 printPath(parent, i, source);
 cout << ": " << dist[i] << endl;
 }
}
int main() {
 int V;
 cin >> V;
 vector<Edge> edges;
 for (int i = 0; i < V; ++i) {
 for (int j = 0; j < V; ++j) {
 int weight;
 cin >> weight;
 if (weight != 0) {
 edges.push_back({i, j, weight});
 }
 }
 }
 int source;
 cin >> source;
 source--; // converting to 0-based index
 int E = edges.size();
 bellmanFord(edges, V, E, source);
 return 0;
}