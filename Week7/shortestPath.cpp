/*After end term examination, Akshay wants to party with his friends. All his friends
are living as paying guest and it has been decided to first gather at Akshay’s house
and then move towards party location. The problem is that no one knows the exact
address of his house in the city. Akshay as a computer science wizard knows how to
apply his theory subjects in his real life and came up with an amazing idea to help his
friends. He draws a graph by looking in to location of his house and his friends’
location (as a node in the graph) on a map. He wishes to find out shortest distance and
path covering that distance from each of his friend’s location to his house and then
whatsapp them this path so that they can reach his house in minimum time. Akshay
has developed the program that implements Dijkstra’s algorithm but not sure about
correctness of results. Can you also implement the same algorithm and verify the
correctness of Akshay’s results? (Hint: Print shortest path and distance from friends’
location to Akshay’s house).*/

#include <bits\stdc++.h>
using namespace std;
typedef pair<int, int> pii; // {distance, vertex}
void printPath(vector<int>& parent, int vertex, int source) {
 if (vertex == source) {
 cout << source + 1 << " : ";
 return;
 }
 printPath(parent, parent[vertex], source);
 cout << vertex + 1 << " ";
}
void dijkstra(vector<vector<pii>>& graph, int V, int source) {
 vector<int> dist(V, INT_MAX);
 vector<int> parent(V, -1);
 priority_queue<pii, vector<pii>, greater<pii>> pq; // minheap
 dist[source] = 0;
 pq.push({0, source});
 while (!pq.empty()) {
 int u = pq.top().second;
 int current_dist = pq.top().first;
 pq.pop();
 if (current_dist > dist[u]) continue; // Skip if a
shorter path is already found
Input:
5
0 4 1 0 0
0 0 0 0 4
0 2 0 4 0
0 0 0 0 4
0 0 0 0 0
1
Output:
1 : 0
1 : 3 2 : 3
1 : 3 : 1
1 : 3 4 : 5
1 : 3 2 5 : 7
 for (auto& edge : graph[u]) {
 int v = edge.first;
 int weight = edge.second;
 if (dist[u] + weight < dist[v]) {
 dist[v] = dist[u] + weight;
 parent[v] = u;
 pq.push({dist[v], v});
 }
 }
 }
 // Print the shortest paths
 for (int i = 0; i < V; ++i) {
 if (i == source) {
 cout << source + 1 << " : 0" << endl;
 continue;
 }
 if (dist[i] == INT_MAX) {
 cout << "No path from " << source + 1 << " to " <<
i + 1 << endl;
 continue;
 }
 printPath(parent, i, source);
 cout << ": " << dist[i] << endl;
 }
}
int main() {
 int V;
 cin >> V;
 vector<vector<pii>> graph(V);
 for (int i = 0; i < V; ++i) {
 for (int j = 0; j < V; ++j) {
 int weight;
 cin >> weight;
 if (weight != 0) {
 graph[i].push_back({j, weight});
 }
 }
 }
 int source;
 cin >> source;
 source--; // converting to 0-based index
 dijkstra(graph, V, source);
 return 0;
}
