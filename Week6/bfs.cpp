/*Given a graph, design an algorithm and implement it using a
program to find if a graph is bipartite or not. (Hint: use BFS)
Input Format:
Input will be the graph in the form of adjacency matrix or adjacency list.
Output Format:
Output will be 'Yes Bipartite' if graph is bipartite, otherwise print 'Not
Bipartite'. */

#include<bits/stdc++.h>
using namespace std;
bool DFS(vector<vector<int> >&adj,int src,int dest,int vis[]){
int n=adj.size();
 if(src==dest)
 return true;
 vis[src]=1;
 for(int i=0;i<n;i++ ){
 if(!vis[i] && adj[src][i]==1){
 if(DFS(adj,i,dest,vis))
 return true;
 }
 }
 return false;
}
int main(){
 int n;
 cin>>n;
 vector<vector<int> >adj(n,vector<int>(n,0));
 int u,v,src,dest;
 for(int i=0;i<n;i++){
 for(int j=0;j<n;j++)
 cin>>adj[i][j];
 }
 cin>>src>>dest;
 int vis[n]={0};
 if(DFS(adj,src,dest,vis)){
 cout<<"Yes Path Exists.";
 }
 else{
 cout<<"No Such Path Exists";
 }
 return 0;
}