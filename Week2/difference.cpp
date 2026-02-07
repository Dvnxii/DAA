/*
3. Given an array of nonnegative integers, design an algorithm and 
a program to count the number of pairs of integers such that their 
difference is equal to a given key, K. 

Input format: 
The first line contains number of test cases, T. For each test case, 
there will be three input lines. First line contains n (the size of array). 
Second line contains space-separated integers describing array. Third 
line contains the key element. 

Output format: 
The output will have T number of lines. 
For each test case T, output will be the total count i.e. number of times 
such pair exists. 
Sample 1/O Problem IlI: 
Input: Output: 
2 
2 
5 
4 
151842131 
20 
10 
247116 921228481420 22 
4
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countPairs(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int count = 0;
    for (int x : arr) {
        freq[x]++;
    }

    for (int x : arr) {
        if (freq.find(x + k) != freq.end()) {
            count += freq[x + k];
        }
        if (k != 0 && freq.find(x - k) != freq.end()) {
            count += freq[x - k];
        }
    }
    return count / 2;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        cout << countPairs(arr, k) << endl;
    }

    return 0;
}