/*Given a directed graph with two vertices ( source and destination). Design an
algorithm and implement it using a program to find the weight of the shortest path
from source to destination with exactly k edges on the path.*/

#include <bits/stdc++.h>
using namespace std;
int findShortestPathWeightKEdges(int V, vector<vector<int>>&
graph, int src, int dest, int k) {
 const int INF = INT_MAX;
 vector<vector<int>> dp(k + 1, vector<int>(V, INF));
 // Base case: 0 edges to reach src
 dp[0][src - 1] = 0;

 for (int e = 1; e <= k; ++e) {
 for (int u = 0; u < V; ++u) {
 for (int v = 0; v < V; ++v) {
 if (graph[u][v] != 0 && dp[e - 1][u] != INF) {
 if (dp[e - 1][u] + graph[u][v] < dp[e][v])
{
 dp[e][v] = dp[e - 1][u] + graph[u][v];
 }
 }
 }
 }
 }
 return dp[k][dest - 1] == INF ? -1 : dp[k][dest - 1];
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
 int src, dest;
 cin >> src >> dest;
 int k;
 cin >> k;
 t, k);
 if (result != -1) {
 cout << "Weight of shortest path from (" << src << ","
<< dest << ") with " << k << " edges : " << result << endl;
 } else {
 cout << "no path of length k is available" << endl;
 }
 return 0;
}

