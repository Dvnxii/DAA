/*
3. 
Given an unsorted array of positive integers, design an algorithm 
and implement it using a program to find whether there are any 
duplicate elements in the array or not. (use sorting) (Time Complexity = 
O(n log n)) 
Input Format: 
The first line contains number of test cases, T. For each test case, 
there will be two input lines. First line contains n (the size of array). 
Second line contains space-separated integers describing array. 
Output Format: 
The output will have T number of lines. 
For each test case, output will be 'YES' if duplicates are present 
otherwise ‘NO’. 
Sample 1/O Problem IlI: 
Input: Output: 
3 
NO 
5 
YES 
2852831475 
10 
NO 
756516526862758 
15 
75358657 982373 164811906119 20 
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    bool duplicate = false;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            duplicate = true;
            break;
        }
    }

    if (duplicate)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
