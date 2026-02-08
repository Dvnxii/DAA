/*
2. Given an unsorted array of integers, design an algorithm and 
implement a program to sort this array using selection sort. Your 
program should also find number of comparisons and number of swaps 
required. 
Input Format: 
The first line contains number of test cases, T. For each test case, 
there will be two input lines. First line contains n (the size of array). 
Second line contains space-separated integers describing array. 
Output Format: 
The output will have T number of lines. 
For each test case T, there will be three output lines. First line will give 
the sorted array. 
Second line will give total number of comparisons. Third line will give 
total number of swaps required. 
Sample 1/0 Problem II: 
Input: Output: 
3 -21-13 124546 
6576 89 
8 
comparisons = 28 -1365-2176 46 894512 swaps =7 
10 
21323446 515465767897 
54 6534 76 78 97 46 3251 21 
15 
 comparisons = 45 
swaps =9 
63 42 223 645 652 31 324 22 553 12 54 65 86 46 32512 22 31 42 46 
54 63 65 86 223 324 325 553 645 652 
comparisons = 105 
swaps = 14 
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons = 0;
    int swaps = 0;

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "comparisons = " << comparisons << endl;
    cout << "swaps = " << swaps << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
