/*
l. Given an unsorted array of alphabets containing duplicate 
elements. Design an algorithm and implement it using a program to find  which alphabet has maximum number of occurrences and 
print it. (Time Complexity = O(n)) (Hint: Use counting sort) 
Input Format: 
The first line contains number of test cases, T. For each test case, 
there will be two input lines. First line contains n (the size of array). 
Second line contains space-separated integers describing array. 
Output: 
The output will have T number of lines. 
For each test case, output will be the array element which has 
maximum occurrences and its total number of occurrences. 
If 
no duplicates are present (i.e. all the elements occur only once), 
output should be “No Duplicates Present”. 
Sample 1/O Problem I: 
Input: Output: 
3 
10 
a-3 
No Duplicates Present 
aedwadqgafp 1-4 
15 
rkpgvyumagadjcze 
20 
gtllitcwawglcwdsaavcl 
*/

#include<bits/stdc++.h> 
using namespace std; 
void max_occurrence(vector<char>str)
{   
    int hash[256]={0};
    for(int i=0;i<str.size();i++){     
        hash[str[i]]++;   
    }   
    int max_occ=1;
       char alpha;
      for(int i=0;i<256;i++){
            if(hash[i]>max_occ){      
                 max_occ=hash[i];       
                 alpha=char(i);     
                }   
            }   
            if(max_occ==1){     
                cout<<"No duplicates present"<<endl;   
            }   else{     
                cout<<alpha<<" - "<<max_occ<<endl;  
             } 
            }
            int main(){   
                int t;   
                cin>>t;   
                while(t--){     
                    int n;     
                    cin>>n;     
                    vector<char> str(n);     
                    for(int i=0;i<n;i++){       
                        cin>>str[i];     
                    } 
                max_occurrence(str);   
            } 
        } 