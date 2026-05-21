/*Implement the previous problem using Kruskal's algorithm*/

#include <bits/stdc++.h>
using namespace std;
struct Edge {
 int u, v, weight;
 Edge(int u, int v, int weight) : u(u), v(v),
weight(weight) {}
};
bool compareEdges(const Edge &a, const Edge &b) {
 return a.weight < b.weight;
}
int findRoot(vector<int> &parent, int u) {
 if (parent[u] != u) {
 parent[u] = findRoot(parent, parent[u]);
 }
 return parent[u];
}
void unionSets(vector<int> &parent, vector<int> &rank, int u,
int v) {
 int rootU = findRoot(parent, u);
 int rootV = findRoot(parent, v);
 if (rootU != rootV) {
 if (rank[rootU] > rank[rootV]) {
 parent[rootV] = rootU;
 } else if (rank[rootU] < rank[rootV]) {
 parent[rootU] = rootV;
 } else {
 parent[rootV] = rootU;
 rank[rootU]++;
 }
 }
}
int kruskalMST(vector<vector<int>> &graph, int V) {
 vector<Edge> edges;
 for (int u = 0; u < V; ++u) {
 for (int v = u + 1; v < V; ++v) {
 if (graph[u][v] != 0) {
 edges.emplace_back(u, v, graph[u][v]);
 }
 }
 }
 sort(edges.begin(), edges.end(), compareEdges);
 vector<int> parent(V);
 vector<int> rank(V, 0);
 for (int i = 0; i < V; ++i) {
 parent[i] = i;
}
 int mstWeight = 0;
 int edgesAdded = 0;
 for (const Edge &edge : edges) {
 if (edgesAdded == V - 1) break;
 int u = edge.u;
 int v = edge.v;
 int rootU = findRoot(parent, u);
 int rootV = findRoot(parent, v);
 if (rootU != rootV) {
 unionSets(parent, rank, u, v);
 mstWeight += edge.weight;
 edgesAdded++;
 }
 }
 return mstWeight;
}
int main() {
 int V;
 cin >> V;
 vector<vector<int>> graph(V, vector<int>(V));
 for (int i = 0; i < V; ++i) {
 for (int j = 0; j < V; ++j) {
 cin >> graph[i][j];
 }
 }
 int minCost = kruskalMST(graph, V);
 cout << "Minimum Spanning Weight: " << minCost << endl;
 return 0;
}
