/* Given an unsorted array of integers, design an algorithm and
implement it using a program to find whether two elements exist such
that their sum is equal to the given key element. (Time Complexity =
O(n log n))
Input Format:
The first line contains number of test cases, T. For each test case,
there will be two input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array. Third
line contains key 
Output Format:
The output will have T number of lines.
For each test case, output will be the elements arr|i] and arr{j] such that
arr[i]+arr[j] = key if exist otherwise print '‘No Such Elements Exist”.
Sample 1/O Problem II:
Input: Output:
2 10 40
10 No Such Element Exist
64 28 97 40 1272 84 24 38 10
50
15
56 10729129341456120113991294
302*/

#include<bits/stdc++.h> 
using namespace std; 
void sum_of_two(vector<int>arr,int key){   
    sort(arr.begin(),arr.end());   
    int n=arr.size();   
    int left=0,right=n-1;   
    while(left<right){     
        if(arr[left]+arr[right]>key){       
            right--;     
        }
        else if(arr[left]+arr[right]<key){       
            left++;     
        }     
        else{       
            cout<<arr[left]<<" "<<arr[right]<<endl;       
            return;     
        }   
    }   
    cout<<"No such element exist"<<endl; 
} int main(){   
    int t;    
    cin>>t;   
    while(t--){     
        int n;     
        cin>>n;     
        vector<int> arr(n);     
        for(int i=0;i<n;i++){       
            cin>>arr[i];     
        }     
        int key;     
        cin>>key;     
        sum_of_two(arr,key);   
    } 
}  