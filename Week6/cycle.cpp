/*
Given a directed graph, design an algorithm and implement it using a program to find
whether cycle exists in the graph or not
*/

#include<bits/stdc++.h>
using namespace std;
bool DFS(int node,vector<vector<int> > &adj, int vis[],int
pathVis[] ) {
 vis[node]=1;
 pathVis[node]=1;
 for(int it: adj[node]){
 if(!vis[it]){
 //not visited check for cycle
 if(DFS(it,adj,vis,pathVis)){
 return true;
 }
}
//visited and path visited also
else if(pathVis[it]){
return true;
}
}
pathVis[node]=0;
return false;
}
int main(){
 int n;
 cin >> n;
 vector<vector<int>> adjMatrix(n, vector<int>(n));
 for (int i = 0; i < n; ++i) {
 for (int j = 0; j < n; ++j) {
 cin >> adjMatrix[i][j];
 }
 }
 // Convert adjacency matrix to adjacency list
 vector<vector<int>> adj(n);
 for (int i = 0; i < n; ++i) {
 for (int j = 0; j < n; ++j) {
 if (adjMatrix[i][j] == 1) {
 adj[i].push_back(j);
 }
 }
 }
 int vis[n]={0};
 int pathVis[n]={0};
 for(int i=0;i<n;i++){
 if(!vis[i]){
 if(DFS(i,adj,vis,pathVis)){
 cout<<"Yes Cycle exists.";
 return 0;
}
}
 }
 cout<<"No cycle exists.";
 return 0;
}