/*Assume that same road construction project is given to another person. The amount he
will earn from this project is directly proportional to the budget of the project. This
person is greedy, so he decided to maximize the budget by constructing those roads
who have highest construction cost. Design an algorithm and implement it using a
program to find the maximum budget required for the project*/

#include <bits/stdc++.h>
using namespace std;
int primMaxST(vector<vector<int>>& graph, int V) {
 vector<int> key(V, INT_MIN);
 vector<bool> inMST(V, false);
 priority_queue<pair<int, int>> pq;
 int src = 0; // Start from the first city
 pq.push({0, src});
 key[src] = 0;
 int maxSTWeight = 0;
 while (!pq.empty()) {
 int u = pq.top().second;
 pq.pop();
 if (inMST[u]) continue;
 inMST[u] = true;
 maxSTWeight += key[u];
 for (int v = 0; v < V; ++v) {
 if (graph[u][v] != 0 && !inMST[v] && graph[u][v] >
key[v]) {
 key[v] = graph[u][v];
 pq.push({key[v], v});
 }
 }
 }
 return maxSTWeight;
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
 int maxCost = primMaxST(graph, V);
 cout << "Maximum Spanning Weight: " << maxCost << endl;
 return 0;
}
