/* You have been given two sorted integer arrays of size m and n.
Design an algorithm and implement it using a program to find list of
elements which are common to both. (Time Complexity = O(m+n))
Input Format:
First line contains m (the size of first array).
Second line contains m space-separated integers describing first array.
Third line contains n (the size of second array).
Fourth line contains n space-separated integers describing second
array.
Output Format:
Output will be the list of elements which are common to both.
Sample 1/0O Problem IlI: 
Input: Output:
7 10 10 34 55
3476 1039851055
12
305534721034 1089 11 30 69 51 */

#include<bits/stdc++.h>
using namespace std;
void intersection(vector<int>A,vector<int>B){
 int i=0,j=0;
 int m=A.size(),n=B.size();
 vector<int>ans;
 while(i<m && j<n){
 if(A[i]==B[j]){
 ans.push_back(A[i]);
 i++;
 j++;
 }
 else if(A[i]<B[j]){
 i++;
 }
 else{
 j++;
 }
 }
 for(auto it:ans){
 cout<<it<<" "
  }
}
int main(){
 int m,n;
 cin>>m;
 vector<int> A(m);
 for(int i=0;i<m;i++){
 cin>>A[i];
 }
 cin>>n;
 vector<int> B(n);
 for(int i=0;i<n;i++){
 cin>>B[i];
 }
 sort(A.begin(),A.end());
 sort(B.begin(),B.end());
 intersection(A,B);

